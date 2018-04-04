#include <iostream>
#include <vector>
#include <map>
#include "Agent.h"
#include "Agent_Type1.h"
#include "Agent_Type2.h"
#include "Map.h"

using namespace std;

int main() {

    Map harta;
  /*  map<int, Agent *> mm;
    mm.insert(make_pair(11, new Agent_Type1));
    mm.insert(make_pair(22, new Agent_Type2));
    mm.insert(make_pair(33, new Agent_Type3));
    mm.find(11)->second->setId(11);
    mm.find(22)->second->setId(22);
    mm.find(33)->second->setId(33);



    cout << harta.luptaAgenti(*(mm.find(33)->second),*(mm.find(11)->second)) << "\n\n";
    cout << harta.luptaAgenti(*(mm.find(11)->second),*(mm.find(22)->second)) << "\n\n";

    cout << "Viata agent 1: " << mm.find(11)->second->getHealth();
    cout << "Viata agent 3: " << mm.find(33)->second->getHealth();*/


   //harta.rundaJoc();

    harta.simulareJoc();


    return 0;
}
