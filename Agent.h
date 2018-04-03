//
// Created by Adrian on 3/29/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_H

#include <utility>
#include <vector>

class Agent {
    int health;
    int damage;
    int speed;
    std::pair<int, int> pozitie;

public:
    void setHealth(int hp);
    const int getHealth();
    void setDamage(int dmg);
    const int getDamage();
    void setSpeed(int spd);
    const int getSpeed();
    void setPosition(int linie, int coloana);
    std::pair<int, int> getPosition();
};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_H
