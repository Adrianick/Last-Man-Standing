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
    int getDamageBonus() const;

    void setSpeedBonus(int spdB);

    int getSpeedBonus() const;

    void setHpBonus(int hpB);

    int getHpBonus() const;

    void setItemId(int id);

    int getItemId() const;

    void setItemPosition(int linie, int coloana);

    std::pair<int, int> getItemPosition();

    virtual void decayItem()=0;
};


#endif //SURVIVALGAMEPOOPROIECT2_ITEM_H
