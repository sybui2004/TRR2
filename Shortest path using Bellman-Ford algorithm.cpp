#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include <vector>
#include <map>
#include <climits>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

int main()
{
    int v, s, x;
    cin >> v >> s;
    vector<Edge> edges;
    vector<vector<vector<int>>> path(v + 1, vector<vector<int>>(v + 1));
    vector<int> d(v + 1, INT_MAX);
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
        {
            cin >> x;
            if (x != 0)
            {
                edges.push_back({i, j, x});
                path[i][j].push_back(i), path[i][j].push_back(j);
            }
        }
    
    path[s][s].push_back(s);
    int E = edges.size();

    d[s] = 0;

    for (int k = 1; k <= v - 1; k++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (d[u] != INT_MAX && d[u] + weight < d[v])
            {
                d[v] = d[u] + weight;
                path[s][v] = path[s][u];
                path[s][v].push_back(v);
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        cout << "K/c " << s << " -> " << i << " = ";
        if (d[i] == INT_MAX)
        {
            cout << "INF;\n";
            continue;
        }
        else
            cout << d[i] << ";";
        
        if (i == s)
        {
            cout << " " << s << " <- " << s << "\n";
            continue;
        }
        for (int j = path[s][i].size() - 1; j > 0; j--)
            cout << " " << path[s][i][j] << " <-";
        cout << " " << path[s][i][0] << endl;
    }
}