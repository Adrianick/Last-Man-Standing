#include "Map.h"
//
// Created by Adrian on 3/30/2018.
//
#include <iostream>
#include <random>
#include <chrono>

Map::Map() {

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    numberOfAgentsAlive = 9;
    numberOfItemsAvailable = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            map[i][j] = 0;
        }
    } /// Harta este goala, doar 0

    for(int i=0; i<3; i++)
    {
        agents.push_back(new Agent_Type1());
        agents[i]->setId(i+1);
        idMap.insert(std::make_pair(i+1, agents[i]));
        int linie, coloana;
        while(1){
            linie = e()%3, coloana = e()%3;
            if(map[linie][coloana] == 0) {
                agents[i]->setPosition(linie, coloana);
                map[linie][coloana] = 1;
                break;
            }
        }
    }





    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << map[i][j] << "  ";
        }
        std::cout << std::endl;
    } /// Afisare Harta
    for(auto it = agents.begin(); it != agents.end(); ++it){
        std::cout << "Coordonatele agentului : "<< (*it)->getId() << " sunt :"<< (*it)->getPosition().first+1 << ", " << (*it)->getPosition().second+1 << "\n";
    }

}

Map::~Map() {

}
