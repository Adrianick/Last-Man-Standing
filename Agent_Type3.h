//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_TYPE3_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_TYPE3_H

#include "Agent.h"

class Agent_Type3 : public Agent {

public:
    Agent_Type3();

    int moveAgent(int map[4][4], std::map<int, Agent *> &agents);
};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_TYPE3_H
