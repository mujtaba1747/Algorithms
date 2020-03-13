#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v)
{
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1 /*&& u != parent[v]*/) { // uncomment for undirected graph
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle(){
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}
int main()
{
 n = 1000;
 adj.resize(1000);
 int x = 1;
 adj[1].push_back(2);
 adj[2].push_back(3);
 adj[3].push_back(4);
 adj[4].push_back(1);
 /*adj[2].push_back(3);
 adj[3].push_back(4);
 adj[4].push_back(5);
 adj[5].push_back(1);*/
 find_cycle();
}
