//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_MAP_H
#define SURVIVALGAMEPOOPROIECT2_MAP_H



#include <vector>
#include <utility>
#include <map>
#include "Agent.h"
#include "Item.h"


class Map {
    int numberOfItemsAvailable; /// cate iteme sunt pe harta nefolosite
    int numberOfAgentsAlive; /// cati agenti in viata sunt
    int mapOfTheGame[15][15]; /// dimensiunea harti
    std::map<int, Agent *> agents;
    std::map<int, Item *> items;

public:
    Map();
   // ~Map();

    void getNrAg();
    void rundaJoc();
    void simulareJoc();
    void simulareRunde();
    void afisareHarta();
    void afisareInformatiiCurente();
    void setNumberOfItemsAvailable(int items);
};



#endif //SURVIVALGAMEPOOPROIECT2_MAP_H
