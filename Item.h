//
// Created by Adrian on 4/3/2018.
//

#ifndef SURVIVALGAMEPOOPROIECT2_ITEM_H
#define SURVIVALGAMEPOOPROIECT2_ITEM_H

#include <iostream>
#include "Agent.h"


class Item {

protected:
    int damageBonus;
    int speedBonus;
    int hpBonus;
    int itemId;
    std::pair<int, int> itemPositionOnMap;

public:
    Item(int damage, int speed, int health);

    void setDamageBonus(int dmgB);  // aici setez damage-ul
    int getDamageBonus();

    void setSpeedBonus(int spdB);

    int getSpeedBonus();

    void setHpBonus(int hpB);

    int getHpBonus();

    void setItemId(int id);

    virtual int getItemId();

    void setItemPosition(int linie, int coloana);

    std::pair<int, int> getItemPosition();

    /// sa fac cat sa dureze sau alteceva virtual


    virtual void decayItem()=0;
};


#endif //SURVIVALGAMEPOOPROIECT2_ITEM_H
