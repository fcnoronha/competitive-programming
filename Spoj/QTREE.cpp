//www.spoj.com/problems/QTREE/

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 31234

vector<pii> adj[maxn];

// SEG TREE

int seg[maxn*4];
int n;

void update(int node, int i, int j, int idx, int x){
    if (i == j) {
        seg[node] = x;
        return;
    }
    int l = 2*node, r = l+1, mid = (i+j)/2;

    if (idx <= mid) update(l, i, mid, idx, x);
    else            update(r, mid+1, j, idx, x);
    seg[node] = max(seg[r], seg[l]);
}

ll query_seg(int node, int i, int j, int a, int b){
    if (a <= i && j <= b) return seg[node];
    if (i > b || a > j) return 0ll;
    int l = 2*node, r = l+1, mid = (i+j)/2;
    ll ansl = query_seg(l, i, mid, a, b);
    ll ansr = query_seg(r, mid+1, j, a, b);
    return max(ansl, ansr);
}

// HLD

int prt[maxn], lvl[maxn], heavy[maxn], head[maxn], pos[maxn], val[maxn];
int cur_pos;

int dfs(int u) {
    int sz = 1, mx_sz = 0;
    for (pii e: adj[u]) {
        int v = e.f, w = e.s;
        if (v == prt[u]) continue;
        val[v] = w;
        prt[v] = u;
        lvl[v] = lvl[u] + 1;
        int c_sz = dfs(v);
        sz += c_sz;
        if (mx_sz < c_sz)
            mx_sz = c_sz, heavy[u] = v;
    }
    return sz;
}

void decompose(int v, int h) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h);
    for (pii x: adj[v]) 
        if (x.f != prt[v] && x.f != heavy[v])
            decompose(x.f, x.f);
}

void init(int root, int n) {
    fr(i, n) {
        heavy[i] = -1;
        head[i] = 0;
        prt[i] = 0;
        lvl[i] = 0;
        pos[i] = 0;
    }
    fr(i, 5*n) seg[i] = 0;
    cur_pos = 0;
    dfs(root);
    decompose(root, root);
}

int query_hld(int a, int b) {
    int res = 0, path_max;
    while (head[a] != head[b]) {
        if (lvl[head[a]] > lvl[head[b]]) swap(a, b);
        path_max = query_seg(1, 0, n-1, pos[head[b]], pos[b]);
        res = max(res, path_max);
        b = prt[head[b]];
    }
    if (lvl[a] > lvl[b]) swap(a, b);
    path_max = query_seg(1, 0, n-1, pos[a]+1, pos[b]);
    res = max(res, path_max);
    return res;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        cin >> n;

        fr(i, n) adj[i].clear();

        vector<pii> edg;
        fr(i, n-1) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
            edg.pb({u, v});
        }

        init(0, n);
        fr(i, n) update(1, 0, n-1, pos[i], val[i]);

        //fr(i, n) {
        //    cout << i << " -- head: " << head[i] << " val: " << val[i] << " pos: " << pos[i] << endl; 
        //}

        string s;
        while (cin >> s && s[0] != 'D') {
            if (s[0] == 'C') {
                int i, ti;
                cin >> i >> ti;
                int u = edg[i-1].f, v = edg[i-1].s;

                if (v == prt[u]) swap(u, v);
                update(1, 0, n-1, pos[v], ti);
                val[v] = ti;
            }
            else {
                int u, v;
                cin >> u >> v;
                u--, v--;
                //cout << "query " << u << " " << v << " === ";
                if (u == v) p(0);
                else p(query_hld(u, v));
            }
        }
    }
}
