//
// Created by Adrian on 4/3/2018.
//

#include "Agent.h"

void Agent::setHealth(int hp){
    health = hp;
}
int Agent::getHealth(){
    return health;
}
void Agent::setDamage(int dmg){
    damage = dmg;
}
int Agent::getDamage(){
    return damage;
}
void Agent::setSpeed(int spd){
    speed = spd;
}
int Agent::getSpeed(){
    return speed;
}
void Agent::setId(int index){
   id = index;
}
int Agent::getId(){
    return id;
}
void Agent::setPosition(int linie, int coloana){
    positionOnMap.first = linie;
    positionOnMap.second = coloana;
}
std::pair<int, int> Agent::getPosition(){
    return positionOnMap;
}

void Agent::setItemEquiped(int item){
    itemEquiped = item;
}
int Agent::getItemEquiped(){
    return itemEquiped;
}

int Agent::luptaAgenti(Agent & agent1, Agent & agent2){ ///agent 1 ataca primul pentru ca are elementul surpriza ;
                                                        /// return cel care moare
    int dmgAgent1 = agent1.getDamage();
    int dmgAgent2 = agent2.getDamage();
    int healthAgent1 = agent1.getHealth();
    int healthAgent2 = agent2.getHealth();
    while(1){
        agent2.setHealth(healthAgent2-dmgAgent1);
        healthAgent2 -= dmgAgent1;
        if(healthAgent2 < 1){
            return agent2.getId();
        }
    agent1.setHealth(healthAgent1-dmgAgent2);
    healthAgent1 -= dmgAgent2;
    if(healthAgent1 < 1){
        return agent1.getId();
        }
    }
}