#include <iostream>
#include "klase_otoci3.h"
using namespace std;

int main()
{
    island<int> isl;
    vector<vector<int>> matrix;

    vector<int> v1;
    short retci, stupci;
    char izbor;
    int unos;

    do
    {

        cout << "==========[IZBORNIK]==========\n1. Izracun za matricu unutar programa\n"
             << "2. Unos vlastite matrice\nx  Izlaz iz programa\n";
        cin >> izbor;

        switch (izbor)
        {

        case '1':

            /* matrix = {{0, 0, 0, 0, 0, 1, 0},
                      {1, 0, 0, 0, 0, 0, 1},
                      {1, 0, 1, 0, 0, 1, 0},
                      {1, 0, 0, 1, 0, 1, 1},
                      {0, 0, 0, 0, 1, 0, 0},
                      {0, 0, 1, 0, 0, 0, 0},
                      {1, 1, 0, 0, 0, 0, 1}};
                      */
            matrix = {{1, 1, 1, 1}, {0, 0, 0, 0}, {1, 1, 0, 0}};

            cout << "Broj otoka iznosi: " << isl.CountIslands(matrix) << endl;

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
                matrix.push_back(v1);
            }

            cout << "Broj otoka iznosi: " << isl.CountIslands(matrix) << endl;

            break;

        case 'x':
            break;
        }
    } while (izbor != 'x');
    return 0;
}
