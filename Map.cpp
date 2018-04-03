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

    numberOfAgentsAlive = 3;
    numberOfItemsAvailable = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            map[i][j] = 0;
        }
    } /// Harta este goala, doar 0

    for(int i=0; i<3; i++)
    {
        idMap.insert(std::make_pair(i+1,new Agent_Type1()));
        /// idMap.find(i+1)->second->setId(i+1);
        int linie, coloana;
        while(1){
            linie = e()%3, coloana = e()%3;
            if(map[linie][coloana] == 0) {
                idMap.find(i+1)->second->setPosition(linie, coloana);
                map[linie][coloana] = i+1;
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

    for(auto it = idMap.begin(); it != idMap.end(); ++it){
        std::cout << "Coordonatele agentului : "<< (*it).first << " sunt :"<< (*it).second->getPosition().first+1 << ", " << (*it).second->getPosition().second+1 << "\n";
    }
    std::cout << "Agenti in viata: " << numberOfAgentsAlive << "\n";
    std::cout << "Iteme pe harta: " << numberOfItemsAvailable << "\n";

}

Map::~Map() {

}

void Map::rundaJoc() {
  /*  for(auto it = agents.begin(); it != agents.end();++it){
        (*it)->moveAgent();
    }*/

}
