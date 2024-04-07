#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

int par[105];
int graph[105][105];
vector<int> path[105];
vector<pair<int, int>> edge[105];
int v, s;

int d[105];

void dijkstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= v; i++)
        d[i] = INT_MAX;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;
        for (int i = 0; i < edge[u].size(); i++)
        {
            int v = edge[u][i].second;
            int uv = edge[u][i].first;
            if (d[v] > du + uv)
            {
                par[v] = u;
                d[v] = du + uv;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    cin >> v >> s;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] != 0)
            {
                edge[i].push_back({graph[i][j], j});
            }
        }

    dijkstra(s);
    for (int i = 1; i <= v; i++)
    {
        cout << "K/c " << s << " -> " << i << " = ";
        if (i == s)
        {
            cout << "0; " << s << " <- " << s << "\n";
            continue;
        }
        if (d[i] == INT_MAX)
        {
            cout << "INF\n";
            continue;
        }
        cout << d[i] << "; ";
        for (int j = i; j != s; j = par[j])
            path[i].push_back(j);

        path[i].push_back(s);

        for (int j = 0; j < path[i].size(); j++)
        {
            if (j == path[i].size() - 1)
            {
                cout << path[i][j];
                break;
            }
            else
                cout << path[i][j] << " <- ";
        }
        cout << "\n";
    }
}
