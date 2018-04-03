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

int Agent_Type1::moveAgent(int mapOfTheGame[3][3], std::map<int, Agent *> &agents) { /// Acesta se va misca doar pe diagonale

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);


    int step = 1;
    if(getSpeed() > 1) step = 1 + e()%getSpeed();  /// setam cati pasi o sa se miste agentul, intre 1 si "speed"

    int pozitieX = getPosition().first, pozitieY = getPosition().second;
    int linie, coloana;
    do {
        switch (e() % 4) {
            case 0:
                linie = -1;
                coloana = -1;
                break;
            case 1:
                linie = -1;
                coloana = 1;
                break;
            case 2:
                linie = 1;
                coloana = -1;
                break;
            case 3:
                linie = 1;
                coloana = 1;
                break;
            default:
                linie = 0;
                coloana = 0;
                break;
        }
    }while(pozitieX + linie > 2 || pozitieY + coloana > 2 || pozitieX + linie < 0 || pozitieY + coloana < 0);

    std::cout << "Agentul " << getId() << "\n";
    std::cout << "pozitieX = " << pozitieX + 1 << "\n";
    std::cout << "pozitieY = " << pozitieY  + 1<< "\n";
    /*std::cout << "pozitieX +linie = " << pozitieX +linie + 1 << "\n";
    std::cout << "pozitieY +coloana= " << pozitieY  +coloana + 1<< "\n";*/
    std::cout << "linie = " << linie << "\n";
    std::cout << "coloana= " << coloana << "\n";

    bool trebuieSters = 0;
        if(mapOfTheGame[pozitieX + linie][pozitieY + coloana] > 0){
            trebuieSters = 1;
            mapOfTheGame[pozitieX][pozitieY] = 0;
        }
        else if(mapOfTheGame[pozitieX + linie][pozitieY + coloana] == 0) {
            setPosition(pozitieX + linie, pozitieY + coloana);
            mapOfTheGame[pozitieX][pozitieY] = 0;
            mapOfTheGame[pozitieX + linie][pozitieY + coloana] = getId();
        }



   for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << mapOfTheGame[i][j] << "  ";
        }
        std::cout << std::endl;
    } /// Afisare Harta

    if(trebuieSters == 1)
        return getId();

    return -1;
}
