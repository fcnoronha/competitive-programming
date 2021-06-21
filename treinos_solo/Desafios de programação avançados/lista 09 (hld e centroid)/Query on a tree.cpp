#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

#define maxn 11234

vector<pii> adj[maxn];
pii edge[maxn];
int cst[maxn];

struct STree {

    vector<long long int> max_val;
    int n;

    STree(int _n): max_val(_n*4), n(_n) {}

    // set A[idx] to val
    void update(int node, int i, int j, int idx, ll val){
        if (i == j) {
            max_val[node] = val;
            return;
        }
        int l = 2*node, r = l+1, mid = (i+j)/2;

        if (idx <= mid) update(l, i, mid, idx, val);
        else            update(r, mid+1, j, idx, val);
        max_val[node] = max(max_val[r], max_val[l]);
    }

    ll query(int node, int i, int j, int a, int b){
        if (a <= i && j <= b) return max_val[node];
        if (i > b || a > j) return 0ll;
        int l = 2*node, r = l+1, mid = (i+j)/2;
        ll ansl = query(l, i, mid, a, b);
        ll ansr = query(r, mid+1, j, a, b);
        return max(ansl, ansr);
    }

    void update(int i, int v) { update(1, 0, n-1, i, v); };
    ll query(int a, int b) { return query(1, 0, n-1, a, b); };
};

STree seg(1);
struct Hld {

    vector<int> prt, lvl, heavy, head, pos;
    int clk;

    int dfs(int u) {
        int sz = 1, mx_sz = 0;
        for (pii aux: adj[u]) {
            int v = aux.f, c = aux.s;
            if (v == prt[u]) continue;
            cst[v] = c;
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
        for (pii x: adj[u]) {
            int v = x.f;
            if (v != prt[u] && v != heavy[u])
                decompose(v, v);
        } 
    }

    // it is better to let the nodes in the tree be 0 indexed
    void init(int root, int n) {
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        prt = vector<int>(n);
        lvl = vector<int>(n);
        pos = vector<int>(n);
        clk = 0;
        dfs(root);
        decompose(root, root);
    }

    // query for the maximum element in a path
    int query(int a, int b) {
        int ans = 0, path_max;
        while (head[a] != head[b]) {
            if (lvl[head[a]] > lvl[head[b]]) swap(a, b);
            path_max = seg.query(pos[head[b]], pos[b]); // CHANGE
            ans = max(ans, path_max);
            b = prt[head[b]];
        }
        if (lvl[a] > lvl[b]) swap(a, b);
        path_max = seg.query(pos[a]+1, pos[b]); // if its edge make pos[a]+1
        ans = max(ans, path_max);
        return ans;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;

        fr(i, n) adj[i].clear();

        fr(i, n-1) {

            int a, b, c; cin >> a >> b >> c;
            a--, b--;

            edge[i] = {a, b};
            adj[a].pb({b, c});
            adj[b].pb({a, c});
        }

        seg = STree(n);

        Hld hld;
        hld.init(0, n);

        fr(i, n) seg.update(hld.pos[i], cst[i]);

        string s;
        while (cin >> s && s[0] != 'D') {

            if (s[0] == 'Q') {

                int a, b; cin >> a >> b;
                a--, b--;
                p(hld.query(a, b));
            }
            else {

                int i, ti; cin >> i >> ti;
                i--;

                int a = edge[i].f, b = edge[i].s;
                if (hld.lvl[a] > hld.lvl[b]) seg.update(hld.pos[a], ti);
                else                         seg.update(hld.pos[b], ti);
            }

        }

    }
}
