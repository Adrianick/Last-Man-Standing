//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_TYPE1_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_TYPE1_H

#include "Agent.h"
#include <map>
#include <vector>

class Agent_Type1 : public Agent{

public:
    Agent_Type1();

    int moveAgent(int map[3][3], std::map<int, Agent *> &agents);
};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_TYPE1_H
