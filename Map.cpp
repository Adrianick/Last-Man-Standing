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

    numberOfAgentsAlive = 20;
    numberOfItemsAvailable = 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            mapOfTheGame[i][j] = 0;
        }
    } /// Harta este goala, doar 0

    for(int i=0; i<8; i++)
    {
        agents.insert(std::make_pair(i+1,new Agent_Type1()));
        agents.find(i+1)->second->setId(i+1);
        int linie, coloana;
        while(1){
            linie = e()%15, coloana = e()%15;
            if(mapOfTheGame[linie][coloana] == 0) {
                agents.find(i+1)->second->setPosition(linie, coloana);
                mapOfTheGame[linie][coloana] = i+1;
                break;
            }
        }
    }
    for(int i=9; i<=14; i++)
    {
        agents.insert(std::make_pair(i+1,new Agent_Type2()));
        agents.find(i+1)->second->setId(i+1);
        int linie, coloana;
        while(1){
            linie = e()%15, coloana = e()%15;
            if(mapOfTheGame[linie][coloana] == 0) {
                agents.find(i+1)->second->setPosition(linie, coloana);
                mapOfTheGame[linie][coloana] = i+1;
                break;
            }
        }
    }

    for(int i=15; i<=20; i++)
    {
        agents.insert(std::make_pair(i+1,new Agent_Type3()));
        agents.find(i+1)->second->setId(i+1);
        int linie, coloana;
        while(1){
            linie = e()%15, coloana = e()%15;
            if(mapOfTheGame[linie][coloana] == 0) {
                agents.find(i+1)->second->setPosition(linie, coloana);
                mapOfTheGame[linie][coloana] = i+1;
                break;
            }
        }
    }
    std::cout << "Harta initiala  arata astfel: \n";
    afisareHarta();
}

Map::~Map() {

}
void Map::simulareJoc() {
    int nrRunde = 0;
        while(numberOfAgentsAlive > 1){
            rundaJoc();
            nrRunde++;
        }
    std::cout << "Numar total de runde : " << nrRunde << "\n";
    std::cout << "SIMULARE TERMINATA! \n";
}

void Map::rundaJoc() {
    for(auto it = agents.begin(); it != agents.end();++it){

        int desters = (*it).second->moveAgent(mapOfTheGame, agents);
        if(desters > 0) {
            numberOfAgentsAlive--;
            delete agents.find(desters)->second;
            agents.erase(desters);
        }
        afisareInformatiiCurente();
       /* std::cout << "Viata agentilor care traiesc: \n";
        for(auto it2 = agents.begin(); it2 != agents.end(); ++it2){
            std::cout << "Agentul numarul " << (*it2).first << " are viata = " << (*it2).second->getHealth() << "\n";
        }
        afisareHarta();*/

    }

   /* for(auto it = agents.begin(); it != agents.end();++it){
        std::cout << (*it).first << " ";
    }
    std::cout << "\n\n";
    std::cout << agents.size() << " marimeRundaSfarsit \n\n";*/



}

void Map::afisareHarta() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            std::cout << mapOfTheGame[i][j] << " ";
            if(mapOfTheGame[i][j] < 10) std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Map::afisareInformatiiCurente(){
    afisareHarta();
    std::cout << "Agenti in viata : " << numberOfAgentsAlive << "\n";
    std::cout << "Iteme pe harta : " << numberOfItemsAvailable << "\n\n";
}