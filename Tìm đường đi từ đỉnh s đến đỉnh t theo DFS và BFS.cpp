#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;

int v, st, en;
int a[105][105];
bool visited[105];

int kt = 0;
vector<int> ans;

void dfs(vector<int> cur)
{
    int t = cur.back();
    visited[t] = true;
    if (t == en)
    {
        ans = cur;
        kt = 1;
        return;
    }
    for (int i = v; i >= 1; i--)
        if (a[t][i] == 1 && !visited[i])
        {
            vector<int> tmp = cur;
            tmp.push_back(i);
            dfs(tmp);
            visited[i] = false;
        }
}

void bfs()
{
    queue<vector <int> > q;
    q.push({st});
    visited[st] = true;
    while (!q.empty())
    {
        vector <int> front = q.front();
        q.pop();
        int t = front.back();
        if (t == en)
        {
            ans = front;
            kt = 1;
            return;
        }
        for (int i = 1; i <= v; i++)
            if (a[t][i] == 1 && !visited[i])
            {
                vector<int> tmp = front;
                tmp.push_back(i);
                q.push(tmp);
                visited[i] = 1;
            }
    }
}

int main()
{
    cin >> v;
    cin >> st >> en;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            cin >> a[i][j];

    dfs({st});
    if (!kt)
    {
        cout << "no path";
        return 0;
    }

    cout << "DFS path: ";
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    memset(visited, 0, sizeof(visited));
    ans.clear();
    cout << "\n" << "BFS path: ";
    bfs();
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
}