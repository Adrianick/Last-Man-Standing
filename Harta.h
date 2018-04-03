//
// Created by Adrian on 3/30/2018.
//

#ifndef PROIECT2POOSURVIVALGAME_HARTA_H
#define PROIECT2POOSURVIVALGAME_HARTA_H

#include <vector>
#include <utility>
#include "Agent.h"

class Harta {
    int map[15][15];
    std::vector<std::pair<Agent *, int> >agenti;


public:
    Harta();

    ~Harta();

    void updatePozitiiHarta();

    int simulareRunda();

    void simulareJoc(int nrAgenti);
    int getNrAgentiInViata();
    void setNrAgentiInViata(int nrAgenti);
};


#endif //PROIECT2POOSURVIVALGAME_HARTA_H
