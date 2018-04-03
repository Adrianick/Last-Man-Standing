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
            mapOfTheGame[i][j] = 0;
        }
    } /// Harta este goala, doar 0

    for(int i=0; i<3; i++)
    {
        agents.insert(std::make_pair(i+1,new Agent_Type1()));
        agents.find(i+1)->second->setId(i+1);
        int linie, coloana;
        while(1){
            linie = e()%3, coloana = e()%3;
            if(mapOfTheGame[linie][coloana] == 0) {
                agents.find(i+1)->second->setPosition(linie, coloana);
                mapOfTheGame[linie][coloana] = i+1;
                break;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << mapOfTheGame[i][j] << "  ";
        }
        std::cout << std::endl;
    } /// Afisare Harta

    for(auto it = agents.begin(); it != agents.end(); ++it){
        std::cout << "Coordonatele agentului : "<< (*it).first << " sunt :"<< (*it).second->getPosition().first+1 << ", " << (*it).second->getPosition().second+1 << "\n";
    }
    std::cout << "Agenti in viata: " << numberOfAgentsAlive << "\n";
    std::cout << "Iteme pe harta: " << numberOfItemsAvailable << "\n";

}

Map::~Map() {

}

void Map::rundaJoc() {
    std::cout << agents.size() << " marimeRundaInceput \n\n";
    std::vector<int> agentiDeSters;
    for(auto it = agents.begin(); it != agents.end();++it){
        int desters = (*it).second->moveAgent(mapOfTheGame, agents);
        if(desters > 0)
            agentiDeSters.push_back(desters);
    }

    std::cout << "Agenti de sters: ";
    for(auto it = agentiDeSters.begin(); it != agentiDeSters.end();++it){
        std::cout << *it << " ";
        delete agents.find(*it)->second;
        agents.erase(*it);
    }
    std::cout << "\n\n";

    for(auto it = agents.begin(); it != agents.end();++it){
        std::cout << (*it).first << " ";
    }
    std::cout << "\n\n";
    std::cout << agents.size() << " marimeRundaSfarsit \n\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << mapOfTheGame[i][j] << "  ";
        }
        std::cout << std::endl;
    } /// Afisare Harta
}
