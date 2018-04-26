//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_TYPE1_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_TYPE1_H

#include "Agent.h"
#include <map>
#include <vector>
#include "Item.h"
#include "Map.h"

class Agent_Type1 : public Agent{

public:
    Agent_Type1();

    int moveAgent(int map[15][15], std::map<int, Agent *> &agents, std::map<int, Item *> &items) override;
    void itemEquip(Item * item) override ;
};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_TYPE1_H
