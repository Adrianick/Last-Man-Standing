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
    ///  if() - verify what type of agent is
    a.setDamage(a.getDamage()+getDamageBonus());
    a.setHealth(a.getHealth()+getHpBonus());
}

void Item_Type1::zi(){
    std::cout << "item1 \n";
}