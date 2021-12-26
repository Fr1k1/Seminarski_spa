#include <iostream>
#include <vector>
using namespace std;

template <typename elementtype>

class island
{

private:
    bool Condition(vector<vector<int>> &matrix, int i, int j, int r, int c)
    {

        return !(j < 0 || i < 0 || j > (c - 1) || i > (r - 1) || matrix[i][j] != 1);
    }

    void DepthFirstSearch(vector<vector<int>> &matrix, int i, int j, int r, int c)
    {

        if (Condition(matrix, i, j, r, c))
        {

            if (matrix[i][j] == 1)
            {
                matrix[i][j] = 0;
                DepthFirstSearch(matrix, i + 1, j, r, c);
                DepthFirstSearch(matrix, i + 1, j + 1, r, c);
                DepthFirstSearch(matrix, i + 1, j - 1, r, c);
                DepthFirstSearch(matrix, i - 1, j, r, c);
                DepthFirstSearch(matrix, i - 1, j - 1, r, c);
                DepthFirstSearch(matrix, i - 1, j + 1, r, c);
                DepthFirstSearch(matrix, i, j + 1, r, c);
                DepthFirstSearch(matrix, i, j - 1, r, c);
            }
        }
    }

public:
    int countIslands(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int count = 0;
        for (int i = 0; i < r; i++) //za retke
        {
            for (int j = 0; j < c; j++) //za stupce
            {
                if (matrix[i][j] == 1)
                {
                    matrix[i][j] = 0;
                    count++; //ako je element 0, povecaj brojac na 1

                    DepthFirstSearch(matrix, i + 1, j, r, c);     //right side traversal
                    DepthFirstSearch(matrix, i + 1, j + 1, r, c); //upward-right side traversal
                    DepthFirstSearch(matrix, i + 1, j - 1, r, c); //downward-right side traversalmatrix
                    DepthFirstSearch(matrix, i, j + 1, r, c);     //upward side traversal
                    DepthFirstSearch(matrix, i, j - 1, r, c);     //downward side traversalmatrix
                    DepthFirstSearch(matrix, i - 1, j - 1, r, c); //downward-left side traversal
                    DepthFirstSearch(matrix, i - 1, j + 1, r, c); //upward-left side traversal
                    DepthFirstSearch(matrix, i - 1, j, r, c);     //left side traversal
                }
            }
        }
        return count;
    }
};
