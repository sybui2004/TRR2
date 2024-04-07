#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include <vector>
#include <map>
#include <climits>
using namespace std;

bool visited[1000];
vector<vector<int>> edges;
vector<pair<int, int>> Tree_DFS, Tree_BFS;

void DFS(int u)
{
    visited[u] = true;
    for (int v : edges[u])
        if (!visited[v])
        {
            Tree_DFS.push_back({min(u, v), max(u, v)});
            DFS(v);
        }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int v : edges[x])
            if (!visited[v])
            {
                Tree_BFS.push_back({min(x, v), max(x, v)});
                q.push(v);
                visited[v] = true;
            }
    }
}

int main()
{
    int v, s, x;
    cin >> v >> s;
    edges.resize(v + 1);
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
        {
            cin >> x;
            if (x == 1)
                edges[i].push_back(j);
        }

    DFS(s);
    memset(visited, false, sizeof(visited));
    BFS(s);
    cout << "DFS tree\n";
    for (auto i : Tree_DFS)
        cout << i.first << " " << i.second << endl;
    cout << "BFS tree\n";
    for (auto i : Tree_BFS)
        cout << i.first << " " << i.second << endl;
}