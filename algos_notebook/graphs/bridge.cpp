// Tarjan algorithm to find bridges.
// O(V+E)

#define maxn 10000

vector<int> adj[maxn]; // adjacency list of graph

bool vis[maxn];
int tin[maxn], low[maxn];
int timer;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (vis[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                // to-v is a bridge
        }
    }
}

void find_bridges() {
    timer = 0;
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    for (int i = 0; i < maxn; ++i)
        if (!vis[i])
            dfs(i);
}
