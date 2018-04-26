//
// Created by Adrian on 4/4/2018.
//

#include "Item_Type2.h"

Item_Type2::Item_Type2() : Item(45, 2, -30) {}

void Item_Type2::decayItem() {
    if(hpBonus < 0)
        hpBonus += 5;
    if(damageBonus > 0)
        damageBonus -= 7;
}