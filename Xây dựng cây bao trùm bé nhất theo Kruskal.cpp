#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

bool cmp(Edge a, Edge b)
{
    if (a.weight == b.weight)
    {
        if (a.src == b.src)
            return a.dest < b.dest;
        return a.src < b.src;
    }
    return a.weight < b.weight;
}

int v, x;
int par[1005];
vector<Edge> edges;


int par[1005];

int find(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = find(par[u]);
}

void Kruskal()
{
    vector<pair<int, int>> Kruskal_tree;
    int dH = 0;
    sort(edges.begin(), edges.end(), cmp);
    for (auto i : edges)
    {
        int u = find(i.src);
        int v = find(i.dest);
        if (u != v)
        {
            dH += i.weight;
            par[u] = v;
            Kruskal_tree.push_back({i.src, i.dest});
        }
    }

    cout << "dh = " << dH << "\n";
    for (auto i : Kruskal_tree)
        cout << i.first << " " << i.second << "\n";
}
int main()
{
    cin >> v;

    for (int i = 1; i <= v; i++)
    {
        par[i] = i;
        for (int j = 1; j <= v; j++)
        {
            cin >> x;
            if (x != 0 && i < j)
                edges.push_back({i, j, x});
        }
    }

    Kruskal();
}