#include <iostream>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

int v, st;
bool visited[105];
int a[105][105];
vector<int> adj[105];

void DFS(int u, int dem, vector<int> res)
{
    if (dem == v && a[u][st] == 1)
    {
        for (int i : res)
            cout << i << " ";
        cout << st << "\n";
        return;
    }
    visited[u] = true;
    for (int x : adj[u])
        if (!visited[x])
        {
            res.push_back(x);
            DFS(x, dem + 1, res);
            res.pop_back();
        }
    visited[u] = false;
}

int main()
{
    cin >> v >> st;

    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                adj[i].push_back(j);
        }

    DFS(st, 1, {st});
}