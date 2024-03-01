#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int v;
int a[105][105];
bool visited[105];

void dfs(int u)
{
    visited[u] = true;
    for (int i = 1; i <= v; i++)
        if (a[u][i] == 1 && !visited[i])
        {
            dfs(i);
            return;
        }
}

int main()
{
    cin >> v;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            cin >> a[i][j];

    dfs(1);

    for (int i = 1; i <= v; i++)
        if (!visited[i])
        {
            cout << "not strongly connected";
            return 0;
        }
    cout << "strongly connected";
}