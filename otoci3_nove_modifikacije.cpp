#include <iostream>
#include "otoci.h"
using namespace std;

int main()
{
    island<int> isl;
    vector<vector<int>> matrica;

    vector<int> v1;
    short retci, stupci;
    char izbor;
    int unos;

    cout << "==============[IZBORNIK]==============\n1. Izracun za matricu unutar programa\n"
         << "2. Unos vlastite matrice\nx  Izlaz iz programa\n";
    cin >> izbor;

    switch (izbor)
    {

    case '1':

        matrica = {{1, 1, 1, 1, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 0, 0, 1, 1}};

        cout << "Broj otoka iznosi: " << isl.CountIslands(matrica) << endl;

        break;

    case '2':
        cout << "Unesite broj redaka matrice\n";
        cin >> retci;

        cout << "Unesite broj stupaca matrice \n";
        cin >> stupci;

        cout << "Unesite matricu\n";

        for (int i = 0; i < retci; i++)
        {
            vector<int> v1;

            for (int j = 0; j < stupci; j++)
            {
                cin >> unos;
                v1.push_back(unos);
            }
            matrica.push_back(v1);
        }

        cout << "Broj otoka iznosi: " << isl.CountIslands(matrica) << endl;

        break;

    case 'x':
        break;
    }
    return 0;
}
