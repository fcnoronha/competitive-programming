#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 112345

vi adj[maxn];
int seen[maxn], sz[maxn];

void get_sz(int u, int p) {
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        get_sz(v, u);
        sz[u] += sz[v];
    } 
}

int dfs_centroid(int u, int p, int n) {
    for (auto v: adj[u]) {
        if (v == p || seen[v]) continue;
        if (sz[v] > n/2) return dfs_centroid(v, u, n);
    }
    return u;
}

int find_centroid(int r) {
    get_sz(r, r);
    int n = sz[r];
    return dfs_centroid(r, r, n);
}

ll ans;
int mx_sai, d_dest, v_dest;
vi cnt[maxn];

void dfs_dist(int u, int p, int c, int dist) {
    if (seen[u]) return;
    ll amt = (cnt[c].begin() - upper_bound(all(cnt[c]), dist));
    ans += amt;
    for (auto v: adj[u]) 
        if (v != p && seen[v] == 0)
            dfs_dist(v, u, c, dist+1);
}

void dfs_dist2(int u, int p, int dist, int dest) {
    if (dist > mx_sai) return; 
    ans++;
    for (auto v: adj[u]) {
        if (v == dest && dist+1 <= mx_sai) v_dest = u, d_dest = dist+1;
        if (v != p && seen[v] == 0)
            dfs_dist2(v, u, dist+1, dest);
    }
}

void dfs_sai(int u, int p, int dist) {
    if (dist <= 0) return;
    dbg(dist);
    ans--;
    for (auto v: adj[u]) 
        if (v != p || seen[v] == 0)
            dfs_sai(v, u, dist-1);
}

void decompostion(int u, int lvl, int from) {

    int c = find_centroid(u);
    seen[c] = 1;
    for (auto v: adj[c]) {
        if (seen[v]) continue;
        decompostion(v, lvl+1, c);
    }

    sort(all(cnt[c]));
    d_dest = -1; 
    for (auto v: adj[c]) {
        dfs_dist(v, c, c, 1);
        dfs_dist2(v, c, 1, from);
    }

    if (d_dest != -1) {
        cnt[from].pb(mx_sai-d_dest-1);
        dfs_sai(v_dest, from, mx_sai-d_dest-1);
    }

    seen[c] = 0;
}

int main() {
    fastio;

    #ifdef ONLINE_JUDGE
    freopen("awesome.in", "r", stdin);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        mx_sai = (n-1)-l;
        frr(i, n) {
            adj[i].clear();
            cnt[i].clear();
            seen[i] = sz[i] = 0;
        }
        
        fr(i, n-1) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        decompostion(1, 0, 0);
        p(ans);
    }
}
