#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

int v, s;
vector<vector<int>> edges;

void Prim(int s)
{
    bool mark[1005];
    memset(mark, 0, sizeof(mark));
    vector<pair<int, int>> Prim_tree;

    int dH = 0;
    int mi = 1e9, Count = 0, Sum = 0;
    int cur = 0;

    for (int t = 1; t <= v; t++)
        if (mi > edges[s][t] && edges[s][t] != 0)
        {
            mi = edges[s][t];
            cur = t;
        }
    Prim_tree.push_back({s, cur});
    mark[s] = mark[cur] = true;
    dH += mi;
    Count++;
    do
    {
        mi = 1e9;
        int st = 0, en = 0;
        for (int i = 1; i <= v; i++)
            if (mark[i] == true)
                for (int j = 1; j <= v; j++)
                    if (edges[i][j] > 0 && mi > edges[i][j] && mark[j] == 0)
                    {
                        mi = edges[i][j];
                        st = i, en = j;
                    }
        dH += mi;
        if (st && en)
            Prim_tree.push_back({st, en});
        mark[Prim_tree.back().second] = true;
    } while (Prim_tree.size() < v - 1);

    cout << "dH = " << dH << endl;
    for (auto i : Prim_tree)
        cout << min(i.first, i.second) << " " << max(i.first, i.second) << "\n";
}
int main()
{
    cin >> v >> s;
    edges.resize(v + 1);

    for (int i = 1; i <= v; i++)
        edges[i].resize(v + 1);

    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            cin >> edges[i][j];

    Prim(s);
}