//
// Created by Adrian on 4/4/2018.
//

#include "Item_Type3.h"

Item_Type3::Item_Type3() : Item(35, 1, -20) {}

void Item_Type3::decayItem() {
    if (hpBonus < 0)
        hpBonus += 4;
    if (damageBonus > 0)
        damageBonus -= 5;
}