//
// Created by Adrian on 4/3/2018.
//

#include "Item.h"

Item::Item(int damage, int speed, int health) {
    damageBonus = damage;
    speedBonus = speed;
    hpBonus = health;
}


void Item::setDamageBonus(int dmgB) {
    damageBonus = dmgB;
}

int Item::getDamageBonus() const {
    return damageBonus;
}

void Item::setSpeedBonus(int spdB) {
    speedBonus = spdB;
}

int Item::getSpeedBonus() const {
    return speedBonus;
}

void Item::setHpBonus(int hpB) {
    hpBonus = hpB;
}

int Item::getHpBonus() const {
    return hpBonus;
}

void Item::setItemId(int id) {
    itemId = id;
}

int Item::getItemId() const {
    return itemId;
}

void Item::setItemPosition(int linie, int coloana) {
    itemPositionOnMap.first = linie;
    itemPositionOnMap.second = coloana;
}

std::pair<int, int> Item::getItemPosition() {
    return itemPositionOnMap;
}