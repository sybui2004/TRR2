#include <iostream>
#include <queue>
using namespace std;

int v;
int a[105][105];
bool visited[105];

void bfs(int st)
{
    queue<int> q;
    q.push(st);
    visited[st] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for (int i = 1; i <= v; i++)
            if (a[front][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
    }
}

int main()
{
    cin >> v;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            cin >> a[i][j];

    bfs(1);
}