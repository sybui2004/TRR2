#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int v, e, cur, x, p, q;
int a[105][105];
bool visited[105];
vector<pair<int, int>> C;

void dfs(int u)
{
    visited[u] = true;
    for (int i = 1; i <= v; i++)
        if (a[u][i] == 1 && !visited[i])
            dfs(i);
}

void bfs(int n, int x, int y)
{
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= v; i++)
        {
            if (a[u][i] == 1)
            {
                if ((u == x && i == y) || (u == y && i == x))
                    continue;
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
}

int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= v; i++)
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    return cnt;
}

int main()
{
    cin >> v;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1 && i < j)
                C.push_back({i, j});
        }
    
    cur = tplt();

    for (auto it : C)
    {
        int cnt = 0;
        p = it.first, q = it.second;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= v; i++)
            if (!visited[i])
            {
                cnt++;
                bfs(i, p, q);
            }

        if (cnt > cur)
            cout << p << " " << q << "\n";
    }
}