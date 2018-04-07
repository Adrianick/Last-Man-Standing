//
// Created by Adrian on 4/4/2018.
//

#include "Item_Type3.h"

Item_Type3::Item_Type3() {
    setDamageBonus(35);
    setSpeedBonus(1);
    setHpBonus(-20);
}
void Item_Type3::itemEquip(Agent & a) {
    a.setDamage(a.getDamage()+getDamageBonus());
    a.setSpeed(a.getSpeed()+getSpeedBonus());
    if(a.getHealth() > 20)
        a.setHealth(a.getHealth()+getHpBonus());
}