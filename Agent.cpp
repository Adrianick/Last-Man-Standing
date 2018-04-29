//
// Created by Adrian on 4/3/2018.
//

#include "Agent.h"
#include "Item.h"


Agent::Agent(int health, int damage, int speed, int itemEquipedId) {
    this->health = health;
    this->damage = damage;
    this->speed = speed;
    this->itemEquiped = itemEquipedId;
}


void Agent::itemEquip(const Item *item) {

    if ((this->health + item->getHpBonus()) > 0)
        this->health += item->getHpBonus();

    if ((this->damage + item->getDamageBonus()) > 0)
        this->damage += item->getDamageBonus();

    if ((this->speed + item->getSpeedBonus()) > 0)
        this->speed += item->getSpeedBonus();

    this->id = item->getItemId();
}

void Agent::setHealth(int hp) {
    health = hp;
}

int Agent::getHealth() {
    return health;
}

void Agent::setDamage(int dmg) {
    damage = dmg;
}

int Agent::getDamage() {
    return damage;
}

void Agent::setSpeed(int spd) {
    speed = spd;
}

int Agent::getSpeed() {
    return speed;
}

void Agent::setId(int index) {
    id = index;
}

int Agent::getId() {
    return id;
}


void Agent::setPosition(int linie, int coloana) {
    positionOnMap.first = linie;
    positionOnMap.second = coloana;
}

std::pair<int, int> Agent::getPosition() {
    return positionOnMap;
}

void Agent::setItemEquiped(int item) {
    itemEquiped = item;
}

int Agent::getItemEquiped() {
    return itemEquiped;
}

int Agent::luptaAgenti(Agent &agent1, Agent &agent2) { ///agent 1 ataca primul pentru ca are elementul surpriza ;
    /// return cel care moare
    int dmgAgent1 = agent1.damage;
    int dmgAgent2 = agent2.damage;
    int healthAgent1 = agent1.health;
    int healthAgent2 = agent2.health;
    while (1) {
        agent2.health -= agent1.damage;
        healthAgent2 -= dmgAgent1;
        if (healthAgent2 < 1) {
            return agent2.id;
        }
        agent1.health -= agent2.damage;
        healthAgent1 -= dmgAgent2;
        if (healthAgent1 < 1) {
            return agent1.id;
        }
    }
}