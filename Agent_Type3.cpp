//
// Created by Adrian on 4/3/2018.
//

#include "Agent_Type3.h"
#include <random>
#include <iostream>
#include <chrono>
#include <vector>
#include <map>

Agent_Type3::Agent_Type3(){
    setHealth(80);
    setDamage(30);
    setSpeed(1);
    setItemEquiped(0);
}

int Agent_Type3::moveAgent(int mapOfTheGame[15][15], std::map<int, Agent *> &agents, std::map<int, Item *> &items) { /// Acesta se va misca doar pe diagonale

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);


    int step = 1;
    if(getSpeed() > 1) step = 1 + e()%getSpeed();  /// setam cati pasi o sa se miste agentul, intre 1 si "speed"

    int pozitieX = getPosition().first, pozitieY = getPosition().second;
    int linie, coloana;
    do {
        if(getSpeed() > 1) step = 1 + e()%getSpeed();  /// setam cati pasi o sa se miste agentul, intre 1 si "speed"
        switch (e() % 8) {
            case 0:
                linie = -1*step;
                coloana = 0*step;
                break;
            case 1:
                linie = 0*step;
                coloana = 1*step;
                break;
            case 2:
                linie = 1*step;
                coloana = 0*step;
                break;
            case 3:
                linie = 0*step;
                coloana = -1*step;
                break;
            case 4:
                linie = -1*step;
                coloana = -1*step;
                break;
            case 5:
                linie = -1*step;
                coloana = 1*step;
                break;
            case 6:
                linie = 1*step;
                coloana = -1*step;
                break;
            case 7:
                linie = 1*step;
                coloana = 1*step;
                break;
        }
    }while(pozitieX + linie > 14 || pozitieY + coloana > 14 || pozitieX + linie < 0 || pozitieY + coloana < 0);

    int trebuieSters = 0;
   // std::cout << "Agentul: " << getId() << " paseste pe linia: " << pozitieX+linie+1 << " si coloana: " << pozitieY+coloana+1 << "\n";
    std::cout << "Agent: " << getId() << " moved on line : " << pozitieX+linie+1 << " and column: " << pozitieY+coloana+1 << "\n";
    if(mapOfTheGame[pozitieX + linie][pozitieY + coloana] > 0){

        Agent &agentInamic = *(agents.find(mapOfTheGame[pozitieX + linie][pozitieY + coloana])->second);
        trebuieSters = luptaAgenti(*this, agentInamic);
        mapOfTheGame[pozitieX][pozitieY] = 0;
        //std::cout << "O lupta a avut loc intre agentul: " << getId() << " si agentul: " << agentInamic.getId() << " \n";
        std::cout << "A fight began as agent: " << getId() << " attacked agent: " << agentInamic.getId() << " \n";
        if(agentInamic.getHealth() < 1) {
            mapOfTheGame[pozitieX+linie][pozitieY+coloana] = getId();
            setPosition(pozitieX + linie, pozitieY + coloana);
            //std::cout << "Agentul: " << getId() << " a castigat lupta si a ramas cu : " << getHealth() << " viata" << " \n";
            std::cout << "Agent: " << getId() << " won the duel remaining with : " << getHealth() << " health" << " \n";
        }else std::cout << "Agent: " << agentInamic.getId() << " won the duel remaining with : " << agentInamic.getHealth() << " health" << " \n";
            //std::cout << "Agentul: " << agentInamic.getId() << " a castigat lupta si a ramas cu : " << agentInamic.getHealth() << " viata" << " \n";
    }
    else if(mapOfTheGame[pozitieX + linie][pozitieY + coloana] == 0) {
        setPosition(pozitieX + linie, pozitieY + coloana);
        mapOfTheGame[pozitieX][pozitieY] = 0;
        mapOfTheGame[pozitieX + linie][pozitieY + coloana] = getId();
    } else{ /// Calcam pe un item

        setPosition(pozitieX + linie, pozitieY + coloana);
        mapOfTheGame[pozitieX][pozitieY] = 0;
        items.find(mapOfTheGame[pozitieX + linie][pozitieY +coloana])->second->itemEquip(*this);

        std::cout << " Item " << items.find(mapOfTheGame[pozitieX + linie][pozitieY + coloana])->second->getItemId()
                  << " was found by agent: " << this->getId() << " and has damage: "
                  << getDamage() << " , health : " << getHealth() << " and speed " << getSpeed() <<" \n";

       /* std::cout << " Item-ul " << items.find(mapOfTheGame[pozitieX + linie][pozitieY + coloana])->second->getItemId()
                  << " a fost gasit de agentul: " << this->getId() << " si are damage: "
                  << getDamage() << " , viata : " << getHealth() << " si viteza " << getSpeed() <<" \n";*/

        delete items.find(mapOfTheGame[pozitieX + linie][pozitieY + coloana])->second;
        items.erase(mapOfTheGame[pozitieX + linie][pozitieY + coloana]);

        setItemEquiped(mapOfTheGame[pozitieX + linie][pozitieY + coloana]);
        //std::cout << "aaaaaaaaa Item equiped " << getItemEquiped() << "\n";
        mapOfTheGame[pozitieX + linie][pozitieY + coloana] = getId();
    }


    //// trebuie sa dau return la Agentul care trebuie sters in functie de lupta dintre ei
    if(trebuieSters > 0)
        return trebuieSters;

    return -1;
}

