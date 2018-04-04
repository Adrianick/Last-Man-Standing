//
// Created by Adrian on 4/3/2018.
//

#include "Agent_Type1.h"
#include <random>
#include <iostream>
#include <chrono>
#include <vector>
#include <map>

Agent_Type1::Agent_Type1() {
    setHealth(100);
    setDamage(30);
    setSpeed(2);
}

int Agent_Type1::moveAgent(int mapOfTheGame[4][4], std::map<int, Agent *> &agents) { /// Acesta se va misca doar pe diagonale

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);


    int step = 1;


    int pozitieX = getPosition().first, pozitieY = getPosition().second;
    int linie, coloana;
    do {
        if(getSpeed() > 1) step = 1 + e()%getSpeed();  /// setam cati pasi o sa se miste agentul, intre 1 si "speed"
        switch (e() % 4) {
            case 0:
                linie = -1*step;
                coloana = -1*step;
                break;
            case 1:
                linie = -1*step;
                coloana = 1*step;
                break;
            case 2:
                linie = 1*step;
                coloana = -1*step;
                break;
            case 3:
                linie = 1*step;
                coloana = 1*step;
                break;
            default:
                linie = 0*step;
                coloana = 0*step;
                break;
        }
    }while(pozitieX + linie > 2 || pozitieY + coloana > 2 || pozitieX + linie < 0 || pozitieY + coloana < 0);

    std::cout << "Agentul " << getId() << "\n";
    std::cout << "pozitieX = " << pozitieX + 1 << "\n";
    std::cout << "pozitieY = " << pozitieY  + 1<< "\n";
    std::cout << "linie = " << linie << "\n";
    std::cout << "coloana= " << coloana << "\n";

    int trebuieSters = 0;
        if(mapOfTheGame[pozitieX + linie][pozitieY + coloana] > 0){
            Agent &agentInamic = *(agents.find(mapOfTheGame[pozitieX + linie][pozitieY + coloana])->second);
            trebuieSters = luptaAgenti(*this, agentInamic);
            mapOfTheGame[pozitieX][pozitieY] = 0;
            if(agentInamic.getHealth() < 1) {
                mapOfTheGame[pozitieX+linie][pozitieY+coloana] = getId();
                setPosition(pozitieX + linie, pozitieY + coloana);
            }
        }
        else if(mapOfTheGame[pozitieX + linie][pozitieY + coloana] == 0) {
            setPosition(pozitieX + linie, pozitieY + coloana);
            mapOfTheGame[pozitieX][pozitieY] = 0;
            mapOfTheGame[pozitieX + linie][pozitieY + coloana] = getId();
        }



    //// trebuie sa dau return la Agentul care trebuie sters in functie de lupta dintre ei
    if(trebuieSters > 0)
        return trebuieSters;

    return -1;
}
