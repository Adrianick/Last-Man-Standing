#include <iostream>
#include "Agent_Type1.h"


using namespace std;

int main() {

    Map harta;

    cout << "Alegeti una dintre urmatoarele optiuni pentru a incepe simularea : \n";
    cout << "Tasta 1 : Vreau sa vad tot jocul ! \n";
    cout << "Tasta 2 : Vreau sa vad runda cu runda ! \n";

    char n;
    while (1) {
        cin >> n;
        if ((n - 48) == 1) {
            harta.simulareJoc();
            break;
        }
        if ((n - 48) == 2) {
            harta.simulareRunde();
            break;
        }
        cout << "Introduceti tasta 1 sau 2! \n";
    }

    return 0;
}
