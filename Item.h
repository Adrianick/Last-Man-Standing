//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_ITEM_H
#define SURVIVALGAMEPOOPROIECT2_ITEM_H

#include <iostream>
#include "Agent.h"


class Item {
    int damageBonus;
    int speedBonus;
    int hpBonus;
    int itemId;
    std::pair<int, int> itemPositionOnMap;

public:
    void setDamageBonus(int dmgB);  // aici setez damage-ul
    int getDamageBonus();
    void setSpeedBonus(int spdB);
    int getSpeedBonus();
    void setHpBonus(int hpB);
    int getHpBonus();
    void setItemId(int id);
    int getItemId();
    void setItemPosition(int linie,int coloana);
    std::pair<int, int> getItemPosition();

    virtual void itemEquip(Agent & a){};
};


#endif //SURVIVALGAMEPOOPROIECT2_ITEM_H
