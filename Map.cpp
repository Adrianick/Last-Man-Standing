#include "Map.h"
//
// Created by Adrian on 3/30/2018.
//
#include <iostream>
#include <random>
#include <chrono>
#include "Agent.h"
#include "Agent_Type1.h"
#include "Agent_Type2.h"
#include "Agent_Type3.h"
#include "Item.h"
#include "Item_Type1.h"
#include "Item_Type2.h"
#include "Item_Type3.h"


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

    for(int i=1; i<=9; i++) /// Creare agent_type1 in numar de 9
    {
        agents.insert(std::make_pair(i,new Agent_Type1()));
        agents.find(i)->second->setId(i);
        int linie, coloana;
        while(1){
            linie = e()%15, coloana = e()%15;
            if(mapOfTheGame[linie][coloana] == 0) {
                agents.find(i)->second->setPosition(linie, coloana);
                mapOfTheGame[linie][coloana] = i;
                break;
            }
        }
    }
    for(int i=10; i<=15; i++) /// Creare agent_type2 in numar de 6
    {
        agents.insert(std::make_pair(i,new Agent_Type2()));
        agents.find(i)->second->setId(i);
        int linie, coloana;
        while(1){
            linie = e()%15, coloana = e()%15;
            if(mapOfTheGame[linie][coloana] == 0) {
                agents.find(i)->second->setPosition(linie, coloana);
                mapOfTheGame[linie][coloana] = i;
                break;
            }
        }
    }

    for(int i=16; i<=20; i++) /// Creare agent_type3 in numar de 5
    {
        agents.insert(std::make_pair(i,new Agent_Type3()));
        agents.find(i)->second->setId(i);
        int linie, coloana;
        while(1){
            linie = e()%15, coloana = e()%15;
            if(mapOfTheGame[linie][coloana] == 0) {
                agents.find(i)->second->setPosition(linie, coloana);
                mapOfTheGame[linie][coloana] = i;
                break;
            }
        }
    }


    for(int i=-1; i>=-5; i--) /// Creare item_type1 in numar de 5
    {
        items.insert(std::make_pair(i,new Item_Type1()));
        items.find(i)->second->setItemId(i);
        int linie, coloana;
        while(1){
            linie = e()%15, coloana = e()%15;
            if(mapOfTheGame[linie][coloana] == 0) {
                items.find(i)->second->setItemPosition(linie, coloana);
                mapOfTheGame[linie][coloana] = i;
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
    std::cout << "Agentul castigator este : " << agents.begin()->first << "\n";
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
        numberOfItemsAvailable = items.size();
    }
    afisareInformatiiCurente();
}

void Map::afisareHarta() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            std::cout << mapOfTheGame[i][j] << " ";
            if(mapOfTheGame[i][j] < 10 && mapOfTheGame[i][j] >= 0) std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Map::afisareInformatiiCurente(){
    afisareHarta();
    std::cout << "Agenti in viata : " << numberOfAgentsAlive << "\n";
    std::cout << "Iteme pe harta : " << numberOfItemsAvailable << "\n\n";
}