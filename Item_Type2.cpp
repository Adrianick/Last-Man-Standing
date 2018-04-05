//
// Created by Adrian on 4/4/2018.
//

#include "Item_Type2.h"

Item_Type2::Item_Type2() {
    setDamageBonus(45);
    setSpeedBonus(2);
    setHpBonus(-30);
}
void Item_Type2::itemEquip(Agent & a) {
    ///  if() - verify what type of agent is
    a.setDamage(a.getDamage()+getDamageBonus());
    a.setSpeed(a.getSpeed()+getSpeedBonus());
    if(a.getHealth() > 30)
        a.setHealth(a.getHealth()+getHpBonus());
}

void Item_Type2::zi(){
    std::cout << "item2 \n";
}