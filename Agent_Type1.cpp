//
// Created by Adrian on 4/3/2018.
//

#include "Agent_Type1.h"
#include <random>
#include <chrono>

Agent_Type1::Agent_Type1() : Agent(100, 30, 2, 0) {}

void Agent_Type1::itemEquip(Item *item) {

    if ((this->health + item->getHpBonus()) > 0)
        this->health += item->getHpBonus();

    if ((this->damage + item->getDamageBonus()) > 0)
        this->damage += item->getDamageBonus();

    if (item->getSpeedBonus() > 1)
        if ((this->speed + item->getSpeedBonus()) > 0)
            this->speed += item->getSpeedBonus();

    this->itemEquiped = item->getItemId();
}

/// Agentul 1 cauta un item mai presus de orice, din cauza asta, daca nici un item nu e in raza lui de actiune
/// o sa verifice doar  daca pozitia in care se indreapta este  > 0 (agent) sau else (gol)
int Agent_Type1::moveAgent(int mapOfTheGame[15][15], std::map<int, Agent *> &agents,
                           std::map<int, Item *> &items) { /// Acesta se va misca doar pe diagonale

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);


    int step = 1;

    int pozitieX = getPosition().first, pozitieY = getPosition().second;
    int linie = 0, coloana = 0;

    //// tre sa punem linia si coloana sa fie pozitia pe care o sa se duca, directia etc

    int trebuieSters = 0; /// Id-ul celui care va fi sters daca se vor lupta!

    int bestBonus, linieLow, coloanaLow;
    bool sfarsit = false;
    for (int l = -1 * speed; l <= 1 * speed; l++) { /// Verifica tot imprejurul pentru iteme sau agenti
        for (int c = -1 * speed; c <= 1 * speed; c++) {
            if (l == 0 && c == 0)
                continue;
            if ((pozitieX + l) > 14 || (pozitieY + c) > 14 || (pozitieX + l) < 0 || (pozitieY + c) < 0)
                continue;
            if (mapOfTheGame[pozitieX + l][pozitieY + c] < 0) {
                Item *itt = items.find(mapOfTheGame[pozitieX + l][pozitieY + c])->second;
                if (linie == 0) {
                    linie = 1;
                    bestBonus = itt->getDamageBonus() + itt->getHpBonus();
                    linieLow = l;
                    coloanaLow = c;
                }

                ///Toti agentii au functia "ONE SHOT" daca agentul "this" are damage > health inamicului,alege sa lupte
                if (mapOfTheGame[pozitieX + l][pozitieY + c] > 0)
                    if (this->damage - agents.find(mapOfTheGame[pozitieX + l][pozitieY + c])->second->getHealth() >=
                        0) {
                        Agent &agentInamic = *(agents.find(mapOfTheGame[pozitieX + l][pozitieY + c])->second);
                        std::cout << "ONE SHOT !!! \n";
                        std::cout << "Agentul care ataca are damage: " << this->getDamage() << " si inamic are viata: "
                                  << agentInamic.getHealth() << " \n\n";
                        std::cout << "O lupta a avut loc intre agentul: " << this->id << " si agentul: "
                                  << agentInamic.getId() << " \n";
                        std::cout << "Agentul: " << this->getId() << " a castigat lupta si a ramas cu : "
                                  << this->getHealth() << " viata" << " \n";

                        agentInamic.setHealth(agentInamic.getHealth() - this->damage);
                        trebuieSters = agentInamic.getId();
                        mapOfTheGame[pozitieX][pozitieY] = 0;
                        mapOfTheGame[pozitieX + l][pozitieY + c] = this->getId();
                        setPosition(pozitieX + l, pozitieY + c);
                        sfarsit = true;
                    }
                /// Cel mai bun item are bonusul = diferenta dintre ce damage primeste si ce viata pierde
                if (bestBonus < itt->getDamageBonus() + itt->getHpBonus()) {
                    bestBonus = itt->getDamageBonus() + itt->getHpBonus();
                    linieLow = l;
                    coloanaLow = c;
                }

            }
            if (sfarsit)
                break;
        }
        if (sfarsit)
            break;
    }

    if (!sfarsit)
        if (linie) {/// echipeaza itemul cel mai bun

            setPosition(pozitieX + linieLow, pozitieY + coloanaLow);
            mapOfTheGame[pozitieX][pozitieY] = 0;
            this->itemEquip(items.find(mapOfTheGame[pozitieX + linieLow][pozitieY + coloanaLow])->second);

            std::cout << " Item-ul "
                      << items.find(mapOfTheGame[pozitieX + linieLow][pozitieY + coloanaLow])->second->getItemId()
                      << " a fost gasit de agentul: " << this->id << " si are damage: "
                      << this->damage << " , viata : " << this->health << " si viteza " << this->speed << " \n";


            /// Eliberam memoria si setam noua configuratie a hartii
            delete items.find(mapOfTheGame[pozitieX + linieLow][pozitieY + coloanaLow])->second;
            items.erase(mapOfTheGame[pozitieX + linieLow][pozitieY + coloanaLow]);
            setItemEquiped(mapOfTheGame[pozitieX + linieLow][pozitieY + coloanaLow]);
            mapOfTheGame[pozitieX + linieLow][pozitieY + coloanaLow] = this->id;
        } else {
            do {
                if (this->speed > 1)
                    step = 1 + e() %
                               this->speed;  /// setam cati pasi o sa se miste agentul, intre 1 si "speed"
                switch (e() % 8) {
                    case 0:
                        linie = -1 * step;
                        coloana = 0 * step;
                        break;
                    case 1:
                        linie = 0 * step;
                        coloana = 1 * step;
                        break;
                    case 2:
                        linie = 1 * step;
                        coloana = 0 * step;
                        break;
                    case 3:
                        linie = 0 * step;
                        coloana = -1 * step;
                        break;
                    case 4:
                        linie = -1 * step;
                        coloana = -1 * step;
                        break;
                    case 5:
                        linie = -1 * step;
                        coloana = 1 * step;
                        break;
                    case 6:
                        linie = 1 * step;
                        coloana = -1 * step;
                        break;
                    case 7:
                        linie = 1 * step;
                        coloana = 1 * step;
                        break;
                }
            } while (pozitieX + linie > 14 || pozitieY + coloana > 14 || pozitieX + linie < 0 ||
                     pozitieY + coloana < 0);

            std::cout << "Agentul: " << this->id << " paseste pe linia: " << pozitieX + linie + 1 << " si coloana: "
                      << pozitieY + coloana + 1 << "\n";

            if (mapOfTheGame[pozitieX + linie][pozitieY + coloana] > 0) {
                Agent &agentInamic = *(agents.find(mapOfTheGame[pozitieX + linie][pozitieY + coloana])->second);
                trebuieSters = luptaAgenti(*this, agentInamic);
                mapOfTheGame[pozitieX][pozitieY] = 0;

                std::cout << "O lupta a avut loc intre agentul: " << this->id << " si agentul: " << agentInamic.getId()
                          << " \n";

                if (agentInamic.getHealth() < 1) {
                    mapOfTheGame[pozitieX + linie][pozitieY + coloana] = this->id;
                    setPosition(pozitieX + linie, pozitieY + coloana);

                    std::cout << "Agentul: " << this->id << " a castigat lupta si a ramas cu : " << this->health
                              << " viata"
                              << " \n";
                } else
                    std::cout << "Agentul: " << agentInamic.getId() << " a castigat lupta si a ramas cu : "
                              << agentInamic.getHealth() << " viata" << " \n";

            } else { ///mutam pe pozitia noua care este neocupata
                setPosition(pozitieX + linie, pozitieY + coloana);
                mapOfTheGame[pozitieX][pozitieY] = 0;
                mapOfTheGame[pozitieX + linie][pozitieY + coloana] = this->id;
            }

        }
    //// trebuie sa dau return la Agentul care trebuie sters in functie de lupta dintre ei
    if (trebuieSters > 0)
        return trebuieSters;

    return -1;
}

