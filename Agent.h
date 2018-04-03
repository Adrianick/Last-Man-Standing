//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_H

#include <utility>
#include <vector>
#include <iostream>
#include <map>

class Agent {
    int health; /// viata
    int damage; /// puterea
    int speed; /// cate patratele se misca pe harta
    int id; /// daca sunt 10 agenti pe harta si acest agent este al 7-lea atunci ID = 5
    std::pair<int, int> positionOnMap;

public:
    void setHealth(int hp);
    int getHealth();
    void setDamage(int dmg);
    int getDamage();
    void setSpeed(int spd);
    int getSpeed();
    void setId(int index);
    int getId();
    void setPosition(int linie, int coloana);
    std::pair<int, int> getPosition();

    virtual int moveAgent(int mapOfTheGame[3][3], std::map<int, Agent *> &agents){};

};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_H
