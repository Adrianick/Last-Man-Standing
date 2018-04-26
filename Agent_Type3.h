//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_TYPE3_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_TYPE3_H

#include "Agent.h"
#include "Item.h"

class Agent_Type3 : public Agent {

public:
    Agent_Type3();

    int moveAgent(int map[15][15], std::map<int, Agent *> &agents, std::map<int, Item *> &items) override;
    void itemEquip(Item * item) override;
};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_TYPE3_H
