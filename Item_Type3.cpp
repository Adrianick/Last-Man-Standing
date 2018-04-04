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
    ///  if() - verify what type of agent is
    a.setDamage(a.getDamage()+getDamageBonus());
    a.setHealth(a.getHealth()+getHpBonus());
  ////////  a.setSpeed(a.getSpeed()+getSpeedBonus());
}

void Item_Type3::zi(){
    std::cout << "item3 \n";
}