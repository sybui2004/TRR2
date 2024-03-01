#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int v, cur;
int a[105][105];
bool visited[105];


void dfs(int u)
{
    visited[u] = true;
    for (int i = 1; i <= v; i++)
        if (a[u][i] == 1 && !visited[i])
            dfs(i);
}

void bfs(int n, int x)
{
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u != x)
        {
            for (int i = 1; i <= v; i++)
            {
                if(a[u][i] == 1)
                {
                    if (i == x)
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
            cin >> a[i][j];
    
    cur = tplt();

    for (int j = 1; j <= v; j++)
    {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= v; i++)
            if (!visited[i] && i != j)
            {
                cnt++;
                bfs(i, j);
            }

        if (cnt > cur)  
            cout << j << " ";
    }
}