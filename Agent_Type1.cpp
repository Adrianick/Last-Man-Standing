//
// Created by Adrian on 4/3/2018.
//

#include "Agent_Type1.h"
#include <random>
#include <chrono>

Agent_Type1::Agent_Type1() {
    setHealth(100);
    setDamage(30);
    setSpeed(2);
}

std::pair<int, int> Agent_Type1::moveAgent(int map[3][3]) { /// Acesta se va misca doar pe diagonale

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    int step = 1;
    if(getSpeed() > 1) step = 1 + e()%getSpeed();  /// setam cati pasi o sa se miste agentul, intre 1 si "speed"


    short int linie, coloana;
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
        }
    }while(getPosition().first + linie > 3 || getPosition().second + coloana > 3);

    if(map[getPosition().first + linie][getPosition().second + coloana] != 0){
        if(map[getPosition().first + linie][getPosition().second + coloana] > 0){

        }
    }


    return std::make_pair(linie, coloana);
}
