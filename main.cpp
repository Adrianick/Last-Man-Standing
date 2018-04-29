#include <iostream>
#include "Agent_Type1.h"


using namespace std;

int main() {

    char n;
    do {
        while (1) {
            Map harta;
            cout << "Alegeti una dintre urmatoarele optiuni pentru a incepe simularea : \n";
            cout << "Tasta 1 : Vreau sa vad tot jocul ! \n";
            cout << "Tasta 2 : Vreau sa vad runda cu runda ! \n";
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

        cout << "Doriti sa rulati dinou una din optiuni? \n";
        cout << "Y pentru a continua sau orice alta tasta pentru a opri simularea:";
        cin >> n;
    } while (n == 'y' || n == 'Y');

    cout << "Program Terminat!\n";

    return 0;
}
