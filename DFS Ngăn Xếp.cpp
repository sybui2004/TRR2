#include <iostream>
#include <stack>
using namespace std;

int v;
int a[105][105];
bool visited[105];

void dfs(int st)
{
    stack<int> s;
    s.push(st);
    visited[st] = true;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        cout << top << " ";
        for (int i = v; i >= 1; i--)
            if (a[top][i] == 1 && !visited[i])
            {
                s.push(i);
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

    dfs(1);
}