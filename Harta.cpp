//
// Created by Adrian on 3/30/2018.
//
#include <iostream>
#include "Harta.h"
#include "Agent_Type1.h"
#include "Agent_Type2.h"
#include "Agent_Type3.h"

Harta::Harta() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            map[i][j] = 0;
        }
    }

    if (1) {  //// Un total de 9 agenti pe harta, deci 9 indici
        int linie, coloana;
        for (int i = 0; i <= 2; i++) {
            agenti.push_back(std::make_pair(new Agent_Type1, i+1));
            while (1) {
                linie = rand() % 15;
                coloana = rand() % 15;
                if (map[linie][coloana] == 0) {
                    map[linie][coloana] = i + 1; // agentii Agent_Type1 au indicii 1,2,3
                    agenti[i].first->setPosition(linie, coloana);
                    break;
                }
            }
        }

        for (int i = 3; i <= 5; i++) {
            agenti.push_back(std::make_pair(new Agent_Type2, i+1));
            while (1) {
                linie = rand() % 15;
                coloana = rand() % 15;
                if (map[linie][coloana] == 0) {
                    map[linie][coloana] = i + 1;  // agentii Agent_Type2 au indicii 4,5,6
                    agenti[i].first->setPosition(linie, coloana);
                    break;
                }
            }
        }

        for (int i = 6; i <= 8; i++) {
            agenti.push_back(std::make_pair(new Agent_Type3, i+1));
            while (1) {
                linie = rand() % 15;
                coloana = rand() % 15;
                if (map[linie][coloana] == 0) {
                    map[linie][coloana] = i + 1;    // agentii Agent_Type1 au indicii 7,8,9
                    agenti[i].first->setPosition(linie, coloana);
                    break;
                }
            }
        }
    }


    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            std::cout << map[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

Harta::~Harta() {
    for (int i = 0; i < 9; i++)
        delete agenti[i].first;

    agenti.clear();
}

int Harta::simulareRunda() {

    std::pair<int, int> pozitieAgent;
    int nrAleatoriu;

        for(std::vector<std::pair<Agent *, int> >::iterator it = agenti.begin(); it != agenti.end(); ++it) {///move Agent

            (*it).first->moveAgent(agenti,  map, it);
           //agenti[it].first->moveAgent(agenti, map, it);
        }


    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            std::cout << map[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout <<"Agenti in viata: " <<agenti.size();
    return agenti.size();
}

void Harta::simulareJoc(int nrAgenti) {
    while(nrAgenti>1){
       nrAgenti = simulareRunda();
    }
}
