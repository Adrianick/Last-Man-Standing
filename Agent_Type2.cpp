//
// Created by Adrian on 4/3/2018.
//

#include "Agent_Type2.h"
#include <random>
#include <chrono>

Agent_Type2::Agent_Type2() : Agent(120, 35, 1, 0) {}

void Agent_Type2::itemEquip(const Item *item) {

    if (item->getHpBonus() < 0)
        if ((this->health + item->getHpBonus()) > 0)
            this->health += item->getHpBonus();

    if ((this->damage + item->getDamageBonus()) > 0)
        this->damage += item->getDamageBonus();

    if ((this->speed + item->getSpeedBonus()) > 0)
        this->speed += item->getSpeedBonus();

    this->itemEquiped = item->getItemId();
}

/// Agentul 2 cauta sa se lupte mai presus de orice, din cauza asta, daca nici un agent nu e in raza lui de actiune
/// o sa verifice doar  daca pozitia in care se indreapta este  == 0 (goala) sau else (un item)
int Agent_Type2::moveAgent(int mapOfTheGame[15][15], std::map<int, Agent *> const &agents,
                           std::map<int, Item *> &items) { /// Acesta se va misca doar pe diagonale

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    int step = 1;


    int pozitieX = getPosition().first, pozitieY = getPosition().second;
    int linie = 0, coloana = 0;
    //// tre sa punem linia si coloana sa fie pozitia pe care o sa se duca, directia etc

    int trebuieSters = 0; /// Id-ul celui care va fi sters daca se vor lupta!

    int lowestHpAgent, linieLow, coloanaLow;
    bool sfarsit = false;
    for (int l = -1 * speed; l <= 1 * speed; l++) {  /// Verifica tot imprejurul pentru iteme sau agenti
        for (int c = -1 * speed; c <= 1 * speed; c++) {
            if (l == 0 && c == 0)
                continue;
            if ((pozitieX + l) > 14 || (pozitieY + c) > 14 || (pozitieX + l) < 0 || (pozitieY + c) < 0)
                continue;
            if (mapOfTheGame[pozitieX + l][pozitieY + c] > 0) {
                if (linie == 0) {
                    linie = 1;
                    lowestHpAgent = agents.find(mapOfTheGame[pozitieX + l][pozitieY + c])->second->getHealth();
                    linieLow = l;
                    coloanaLow = c;
                }

                ///Toti agentii au functia "ONE SHOT" daca agentul "this" are damage > health inamicului,alege sa lupte
                if (mapOfTheGame[pozitieX + l][pozitieY + c] > 0)
                    if (this->damage - agents.find(mapOfTheGame[pozitieX + l][pozitieY + c])->second->getHealth() >=
                        0) {
                        Agent &agentInamic = *(agents.find(mapOfTheGame[pozitieX + l][pozitieY + c])->second);
                        std::cout << "ONE SHOT !!! \n";
                        std::cout << "Agentul care ataca are damage: " << this->getDamage()
                                  << " si inamic are viata: " << agentInamic.getHealth() << " \n\n";
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
                if (agents.find(mapOfTheGame[pozitieX + l][pozitieY + c])->second->getHealth() <
                    lowestHpAgent) {
                    lowestHpAgent = agents.find(mapOfTheGame[pozitieX + l][pozitieY + c])->second->getHealth();
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
        if (linie) { /// cauta agentul cu viata cea mai mica si il ataca

            Agent &agentInamic = *(agents.find(mapOfTheGame[pozitieX + linieLow][pozitieY + coloanaLow])->second);
            trebuieSters = luptaAgenti(*this, agentInamic);
            mapOfTheGame[pozitieX][pozitieY] = 0;

            std::cout << "O lupta a avut loc intre agentul: " << this->id << " si agentul: " << agentInamic.getId()
                      << " \n";

            if (agentInamic.getHealth() < 1) {
                mapOfTheGame[pozitieX + linieLow][pozitieY + coloanaLow] = this->id;
                setPosition(pozitieX + linieLow, pozitieY + coloanaLow);

                std::cout << "Agentul: " << this->id << " a castigat lupta si a ramas cu : " << this->health << " viata"
                          << " \n";
            } else
                std::cout << "Agentul: " << agentInamic.getId() << " a castigat lupta si a ramas cu : "
                          << agentInamic.getHealth() << " viata" << " \n";
        } else {

            do {
                if (this->speed > 1)
                    step = 1 + e() %
                               this->speed;  /// setam cati pasi o sa se miste agentul, intre 1 si "speed"
                switch (e() % 4) {
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
                }
            } while (pozitieX + linie > 14 || pozitieY + coloana > 14 || pozitieX + linie < 0 ||
                     pozitieY + coloana < 0);


            std::cout << "Agentul: " << this->id << " paseste pe linia: " << pozitieX + linie + 1 << " si coloana: "
                      << pozitieY + coloana + 1 << "\n";

            if (mapOfTheGame[pozitieX + linie][pozitieY + coloana] == 0) { ///mutam pe pozitia noua care este neocupata
                setPosition(pozitieX + linie, pozitieY + coloana);
                mapOfTheGame[pozitieX][pozitieY] = 0;
                mapOfTheGame[pozitieX + linie][pozitieY + coloana] = this->id;
            } else { /// Calcam pe un item
                setPosition(pozitieX + linie, pozitieY + coloana);
                mapOfTheGame[pozitieX][pozitieY] = 0;
                this->itemEquip(items.find(mapOfTheGame[pozitieX + linie][pozitieY + coloana])->second);

                std::cout << " Item-ul "
                          << items.find(mapOfTheGame[pozitieX + linie][pozitieY + coloana])->second->getItemId()
                          << " a fost gasit de agentul: " << this->id << " si are damage: "
                          << this->damage << " , viata : " << this->health << " si viteza " << this->speed << " \n";

                /// Eliberam memoria si setam noua configuratie a hartii
                delete items.find(mapOfTheGame[pozitieX + linie][pozitieY + coloana])->second;
                items.erase(mapOfTheGame[pozitieX + linie][pozitieY + coloana]);
                setItemEquiped(mapOfTheGame[pozitieX + linie][pozitieY + coloana]);
                mapOfTheGame[pozitieX + linie][pozitieY + coloana] = this->id;
            }

        }
    //// trebuie sa dau return la Agentul care trebuie sters in functie de lupta dintre ei
    if (trebuieSters > 0)
        return trebuieSters;

    return -1;
}
