//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_MAP_H
#define SURVIVALGAMEPOOPROIECT2_MAP_H



#include <vector>
#include <utility>
#include <map>
#include "Agent.h"
#include "Agent_Type1.h"
#include "Agent_Type2.h"

class Map {
    short int numberOfItemsAvailable; /// cate iteme sunt pe harta nefolosite
    short int numberOfAgentsAlive; /// cati agenti in viata sunt
    short int map[3][3]; /// dimensiunea harti
    std::map<int, Agent *> idMap;
    std::vector<Agent *> agents;

public:
    Map();
    ~Map();



};



#endif //SURVIVALGAMEPOOPROIECT2_MAP_H
