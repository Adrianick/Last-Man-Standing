//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_TYPE2_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_TYPE2_H

#include "Agent.h"

class Agent_Type2 : public Agent{

public:
    Agent_Type2();

    int moveAgent(int map[15][15], std::map<int, Agent *> &agents);
};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_TYPE2_H
