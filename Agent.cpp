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
std::pair<short int, short int> Agent::getPosition(){
    return positionOnMap;
}