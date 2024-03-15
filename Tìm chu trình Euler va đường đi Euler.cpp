#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int v, st;
int a[105][105];
vector<vector<int>> edges;
vector<int> path;
stack<int> s;

void Euler_Cycle(int u)
{
    s.push(u);
    while (!s.empty())
    {
        int top = s.top();
        if (!edges[top].empty())
        {
            int t = edges[top][0];
            s.push(t);
            edges[top].erase(edges[top].begin());
            for (int i = 0; i < edges[t].size(); i++)
                if (edges[t][i] == top)
                {
                    edges[t].erase(edges[t].begin() + i);
                    break;
                }
        }
        else
        {
            s.pop();
            path.push_back(top);
        }
    }
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

int main()
{
    cin >> v >> st;

    edges.resize(v + 1);

    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                edges[i].push_back(j);
        }

    Euler_Cycle(st);
}