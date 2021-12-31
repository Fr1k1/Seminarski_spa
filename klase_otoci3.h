#include <vector>

template <typename elementtype>

class island
{

private:
    bool Condition(std::vector<std::vector<int>> &matrica, int i, int j, int r, int c)
    {

        return !(j < 0 || i < 0 || j > (c - 1) || i > (r - 1) || matrica[i][j] != 1);
    }

    void DFS_traversal(std::vector<std::vector<int>> &matrica, int i, int j, int r, int c)
    {

        if (Condition(matrica, i, j, r, c))
        {

            if (matrica[i][j] == 1)
            {
                matrica[i][j] = 0;
                DFS_traversal(matrica, i + 1, j, r, c);
                DFS_traversal(matrica, i + 1, j + 1, r, c);
                DFS_traversal(matrica, i + 1, j - 1, r, c);
                DFS_traversal(matrica, i - 1, j, r, c);
                DFS_traversal(matrica, i - 1, j - 1, r, c);
                DFS_traversal(matrica, i - 1, j + 1, r, c);
                DFS_traversal(matrica, i, j + 1, r, c);
                DFS_traversal(matrica, i, j - 1, r, c);
            }
        }
    }

public:
    short CountIslands(std::vector<std::vector<int>> &matrica)
    {
        int r = matrica.size();
        int c = matrica[0].size();
        if (r == 1 && c == 1)
        {
            if (matrica[0][0] == 1)
                return 1;
            else
                return 0;
        }

        short counter = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrica[i][j] == 1)
                {
                    counter++;
                    DFS_traversal(matrica, i, j, r, c);
                }
            }
        }
        return counter;
    }
};
