//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_AGENT_H
#define SURVIVALGAMEPOOPROIECT2_AGENT_H

#include <utility>
#include <vector>
#include <iostream>
#include <map>

class Item;

class Agent {

protected:
    int health; /// viata
    int damage; /// puterea
    int speed; /// cate patratele se misca pe harta
    int id; /// daca sunt 10 agenti pe harta si acest agent este al 7-lea atunci ID = 5
    int itemEquiped;
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

    Agent(int health, int damage, int speed, int itemEquipedId);

    void setPosition(int linie, int coloana);

    std::pair<int, int> getPosition();

    void setItemEquiped(int item);

    int getItemEquiped();

    int luptaAgenti(Agent &agent1, Agent &agent2); /// returnam id-ul celui care trebuie sters!

    virtual int
    moveAgent(int mapOfTheGame[15][15], std::map<int, Agent *> const &agents, std::map<int, Item *> &items)=0;

    virtual void itemEquip(const Item *item)=0;

};


#endif //SURVIVALGAMEPOOPROIECT2_AGENT_H
