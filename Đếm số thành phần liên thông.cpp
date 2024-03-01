#include<iostream>
using namespace std;

int v, ans;
int a[105][105];
bool visited[105];

void dfs(int st)
{
    visited[st] = true;
    for (int i = 1; i <= v; i++) 
        if (a[st][i] == 1 && !visited[i]) dfs(i);
}

int main()
{
    cin >> v;
    for (int i = 1;i <= v; i++)
        for (int j = 1; j <= v; j++)
            cin >> a[i][j];
    
    for (int i = 1; i <= v; i++)
        if (!visited[i]) dfs(i), ans++;

    cout << ans;
}