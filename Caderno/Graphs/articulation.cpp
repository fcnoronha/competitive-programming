#include<bits/stdc++.h>
using namespace std;

// Cuting vertice - articulation point
// Finds vertices that if removed turn the graph into a disconnected one
// O(E+V)

#define maxn 1000 // number of nodes
vector<int> adj[maxn]; // adjacency list of graph

bool visited[maxn];
int tin[maxn], low[maxn];
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1)
                IS_CUTPOINT(v);
            children++;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs(i);

}
