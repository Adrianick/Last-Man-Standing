//
// Created by Adrian on 4/3/2018.
//

#include "Item.h"


void Item::setDamageBonus(int dmgB){
    damageBonus = dmgB;
}
int Item::getDamageBonus(){
    return damageBonus;
}
void Item::setSpeedBonus(int spdB){
    speedBonus = spdB;
}
int Item::getSpeedBonus(){
    return speedBonus;
}
void Item::setHpBonus(int hpB){
    hpBonus = hpB;
}
int Item::getHpBonus(){
    return hpBonus;
}
void Item::setItemId(int id){
    itemId = id;
}
int Item::getItemId(){
    return itemId;
}

void Item::setItemPosition(int linie,int coloana){
    itemPositionOnMap.first = linie;
    itemPositionOnMap.second = coloana;
}
std::pair<int, int> Item::getItemPosition(){
    return itemPositionOnMap;
}