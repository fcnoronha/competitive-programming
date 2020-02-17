// FAST KUHN - MATCHING
// O(sqrt(V) + E) (mais ou menos)

#define maxn 10000 // V

vector<int> adj[maxn];
int l[maxn], r[maxn], seen[maxn];

void add_edge(int a, int b) {
    adj[a].push_back(b);
}

bool dfs(int u) {
    if (seen[u]) return 0;
    seen[u] = 1;

    for (int v: adj[u]) {
        if (r[v] != -1) continue;
        l[u] = v;
        r[v] = u;
        return 1;
    }

    for (int v: adj[u]) {
        if (dfs(r[v])) {
            l[u] = v;
            r[v] = u;
            return 1;
        }
    }
    return 0;
}

int kuhn(int n) {
    ms(l, -1);
    ms(r, -1);
    int ok = 1, cnt = 0;
    while (ok--) {
        ms(seen, 0);
        for (int i = 0; i < n; i++)
            if (l[i] == -1 && dfs(i)) {
                ok = 1;
                cnt++;
            }
    }
    return cnt;
}