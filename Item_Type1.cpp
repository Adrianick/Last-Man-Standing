//
// Created by Adrian on 4/4/2018.
//

#include "Item_Type1.h"


Item_Type1::Item_Type1() : Item(25, 0, 20) {}


void Item_Type1::decayItem() {
    if (hpBonus > 0)
        hpBonus -= 4;
    if (damageBonus > 0)
        damageBonus -= 4;
    if (speedBonus < 3)
        speedBonus++;
}