//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_H

#include <utility>

class Agent {
    short int health; /// viata
    short int damage; /// puterea
    short int speed; /// cate patratele se misca pe harta
    short int id; /// daca sunt 10 agenti pe harta si acest agent este al 7-lea atunci ID = 5
    std::pair<short int, short int> positionOnMap;

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
    std::pair<short int, short int> getPosition();

};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_H
