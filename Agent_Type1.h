//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_TYPE1_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_TYPE1_H

#include "Agent.h"

class Agent_Type1 : public Agent{

public:
    Agent_Type1();

    std::pair<int,int> moveAgent(int map[3][3]);
};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_TYPE1_H
