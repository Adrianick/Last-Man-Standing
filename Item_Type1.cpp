//
// Created by Adrian on 4/4/2018.
//

#include "Item_Type1.h"


Item_Type1::Item_Type1() {
    setDamageBonus(25);
    setSpeedBonus(0);
    setHpBonus(20);
}
void Item_Type1::itemEquip(Agent & a) {
    a.setDamage(a.getDamage()+getDamageBonus());
    a.setHealth(a.getHealth()+getHpBonus());
}
