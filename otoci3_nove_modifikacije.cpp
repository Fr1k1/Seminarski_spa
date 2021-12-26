#include <iostream>
#include "klase_otoci3.h"
using namespace std;

int numIslands(island<int> &isl, vector<vector<int>> &matrica)
{
    int r = matrica.size();
    int c = matrica[0].size();
    if (r == 1 && c == 1)
    {
        if (matrica[0][0] == '1')
            return 1;
        else
            return 0;
    }

    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrica[i][j] == 1)
            {
                ans++;
                isl.DepthFirstSearch(matrica, i, j, r, c);
            }
        }
    }
    return ans;
}

int main()
{
    island<int> isl;
    vector<vector<int>> matrix;

    vector<int> v1;
    int dimenzija;
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

            matrix = {{0, 0, 0, 0, 0, 1, 0},
                      {1, 0, 0, 0, 0, 0, 1},
                      {1, 0, 1, 0, 0, 1, 0},
                      {1, 0, 0, 1, 0, 1, 1},
                      {0, 0, 0, 0, 1, 0, 0},
                      {0, 0, 1, 0, 0, 0, 0},
                      {1, 1, 0, 0, 0, 0, 1}};

            // cout << "Broj otoka iznosi: " << isl.countIslands(matrix) << endl;
            cout << "Broj otoka iznosi: " << numIslands(isl, matrix) << endl;

            break;

        case '2':
            cout << "Unesite dimenziju kvadratne matrice\n";
            cin >> dimenzija;

            cout << "Unesite matricu\n";

            for (int i = 0; i < dimenzija; i++)
            {
                vector<int> v1;

                for (int j = 0; j < dimenzija; j++)
                {
                    cin >> unos;
                    v1.push_back(unos);
                }
                matrix.push_back(v1);
            }

            cout << "Broj otoka iznosi: " << isl.countIslands(matrix) << endl;

            break;

        case 'x':
            break;
        }
    } while (izbor != 'x');
    return 0;
}
