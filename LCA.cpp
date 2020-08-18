// Author : Syed Mujtaba
// Seek knowledge from the Cradle to the Grave !!
// https://www.linkedin.com/in/syed-mujtaba

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, l; // n-total nodes // l - pow(2, l) is max ancestor lvl
vector<vector<int> > adj;
vector<int>lvl;
int timer;
vector<int> tin, tout;
vector<vector<int> > up;

void dfs(int v, int p, int level)
{
    tin[v] = ++timer;
    up[v][0] = p;
    lvl[v] = level;

    for (int i = 1; i <= l; ++i)  // precomputation
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v])
    {
        if (u != p)
            dfs(u, v, level + 1);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) // lfting single node
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int walk(int u, int h)
{
    for(int i = l; i >= 0; i--)
    {
        if((h >> i) & 1)
            u = up[u][i];
    }
    return u;
}

int dis(int u, int v)
{
    return lvl[u] + lvl[v] -2*lvl[lca(u, v)];
}

void preprocess(int root)
{
    tin.resize(n + 1);
    tout.resize(n + 1);
    lvl.resize(n + 1);
    timer = 0;
    // l = ceil(log2(n + 2));  // This is more efficient upper bound

    l = 32; // for walks upto height pow(2, 32)

    up.assign(n + 1, vector<int>(34, -1));
    dfs(root, root, 0);
}

signed main()
{
    cin >> n;
    int x, y;
    adj.resize(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    preprocess(1);
    int q;
    cin >> q;
    while(q--)
    {
        cin >> x >> y;
        cout << lca(x, y) << " " << LCA(x, y) << endl;
    }
    return 0;
}
