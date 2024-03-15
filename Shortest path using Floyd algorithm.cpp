#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int v, x;
    cin >> v;
    vector<vector<vector<int>>> path(v + 1, vector<vector<int>>(v + 1));
    vector<vector<int>> a(v + 1, vector<int>(v + 1, 1e9)), visitable(v + 1, vector<int>(v + 1, 0));
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {

            cin >> x;
            if (i == j)
                a[i][j] = 0;
            else if (x == 0)
                continue;
            else
                a[i][j] = x, visitable[i][j] = 1, path[i][j].push_back(i), path[i][j].push_back(j);
        }
        path[i][i].push_back(i);
    }

    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
            {

                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    path[i][j] = path[i][k];
                    for (int l = 1; l < path[k][j].size(); l++)
                        path[i][j].push_back(path[k][j][l]);
                }
            }

    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
        {
            cout << "K/c " << i << " -> " << j << " = " << a[i][j] << ";";
            for (int p = 0; p < path[i][j].size() - 1; p++)
                cout << " " << path[i][j][p] << "-->";
            cout << " " << path[i][j][path[i][j].size() - 1] << endl;
        }
}