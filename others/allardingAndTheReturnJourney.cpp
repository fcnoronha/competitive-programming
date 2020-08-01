//www.lightoj.com/volume_showproblem.php?problem=1348

#include "bits/stdc++.h"
using namespace std;

const int maxn = 31234;

vector<int> adj[maxn];
int amt[maxn];

// BIT

int bit[maxn];

// [1, i] sum query
int query_b(int i){
    int sm = 0;
    for (; i > 0; i -= i&-i) sm += bit[i];
    return sm;
}

// sum x on position i
void update(int i, int x){
    for (; i < maxn; i += i&-i) bit[i] += x;
}

int query_bit(int i, int j) {
    return query_b(j) - query_b(i-1);
}

// HLD

vector<int> prt, lvl, heavy, head, pos;
int clk;

int dfs(int u) {
    int sz = 1, mx_sz = 0;
    for (int v: adj[u]) {
        if (v == prt[u]) continue;
        prt[v] = u;
        lvl[v] = lvl[u] + 1;
        int c_sz = dfs(v);
        sz += c_sz;
        if (mx_sz < c_sz)
            mx_sz = c_sz, heavy[u] = v;
    }
    return sz;
}

void decompose(int u, int h) {
    head[u] = h, pos[u] = clk++;
    if (heavy[u] != -1)
        decompose(heavy[u], h);
    for (int v: adj[u]) 
        if (v != prt[u] && v != heavy[u])
            decompose(v, v);
}

// it is better to let the nodes in the tree be 0 indexed
void init(int root, int n) {
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    prt = vector<int>(n);
    lvl = vector<int>(n);
    pos = vector<int>(n);
    clk = 1;
    dfs(root);
    decompose(root, root);
}

// query for the maximum element in a path
int query_hld(int a, int b) {
    int ans = 0, path_max;
    while (head[a] != head[b]) {
        if (lvl[head[a]] > lvl[head[b]]) swap(a, b);
        ans += query_bit(pos[head[b]], pos[b]); 
        b = prt[head[b]];
    }
    if (lvl[a] > lvl[b]) swap(a, b);
    ans += query_bit(pos[a], pos[b]);
    return ans;
}

int main() {

    int t; scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {

        int n; scanf("%d", &n);

        memset(bit, 0, sizeof bit);
        for (int i = 0; i < n; i++) {
            scanf("%d", &amt[i]);
            adj[i].clear();
        }

        for (int i = 0; i < n-1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        init(0, n);
        for (int i = 0; i < n; i++) 
            update(pos[i], amt[i]);

        int q; scanf("%d", &q);
        cout << "Case " << tt << ":\n";
        while (q--) {
            int op; scanf("%d", &op);
            if (op == 1) {
                int ii, vv; scanf("%d %d", &ii, &vv);
                update(pos[ii], -amt[ii]+vv);
                amt[ii] = vv;
            }
            else {
                int u, v; scanf("%d %d", &u, &v);
                printf("%d\n", query_hld(u, v));
            }
        }
    }
    return 0;
}
