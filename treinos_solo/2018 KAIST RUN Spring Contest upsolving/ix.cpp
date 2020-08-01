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

#define maxn 1123456

vector<pll> adj[maxn], f1[maxn], fn[maxn]; // from one and from n
pair< pii, ll > edg[maxn]; // {{u,v}, w}

int main() {
    fastio;

    ll n, m, k;
    cin >> n >> m >> k;

    fr(i, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edg[i] = {{u, v}, w};
    }

    if (k > 5) {
        p(-1);
        return 0;
    }

    for (auto e1: adj[1]) {
        ll x = e1.f, w1 = e1.s;
        for (auto e2: adj[x]) {
            ll y = e2.f, w2 = e2.s;
            if (y == 1) continue;
            f1[y].pb({w1+w2, x});
            sort(all(f1[y]));
            if (f1[y].size() > 3) f1[y].pop_back();
        }
    }

    for (auto e1: adj[n]) {
        ll x = e1.f, w1 = e1.s;
        for (auto e2: adj[x]) {
            ll y = e2.f, w2 = e2.s;
            if (y == n) continue;
            fn[y].pb({w1+w2, x});
            sort(all(fn[y]));
            if (fn[y].size() > 3) fn[y].pop_back();
        }
    }

    ll ans = LINF;
    if (k == 1) {
        fr(i, m) {
            ll u = min(edg[i].f.f, edg[i].f.s), v = max(edg[i].f.f, edg[i].f.s);
            if (u != 1 || v != n) continue;
            ans = min(ans, edg[i].s);
        }
    }

    if (k == 2) {
        if (f1[n].size()) ans = f1[n][0].f;
    } 

    if (k == 3) {
        fr(i, m) {
            ll u = edg[i].f.f, v = edg[i].f.s, w = edg[i].s;
            fr(k, 2) {
                swap(u, v);
                if (v == n) for (auto p: f1[u]) {
                    ll x = p.s;
                    if (x == n) continue;
                    ans = min(ans, p.f+w);
                } 
                if (v == 1) for (auto p: fn[u]) {
                    ll x = p.s;
                    if (x == 1) continue;
                    ans = min(ans, p.f+w);
                } 
            }
        }
    }

    if (k == 4) {
        for (int y = 2; y < n; y++) {
            for (auto p1: f1[y]) {
                ll x = p1.s, w1 = p1.f; 
                for (auto p2: fn[y]) {
                    ll z = p2.s, w2 = p2.f;
                    if (x == 1 || z == 1) continue;
                    if (x == n || z == n) continue;
                    if (x == z) continue;
                    ans = min(ans, w1+w2);
                }
            }
        }
    }

    if (k == 5) {
        fr(i, m) {
            ll y = edg[i].f.f, z = edg[i].f.s, we = edg[i].s;
            fr(k, 2) {
                swap(y, z);
                for (auto p1: f1[y]) {
                    ll x = p1.s, w1 = p1.f; 
                    for (auto p2: fn[z]) {
                        ll w = p2.s, w2 = p2.f;
                        if (x == y || x == z || x == w) continue;
                        if (y == z || y == w) continue;
                        if (z == w) continue;
                        if (x == 1 || z == 1 || y == 1 || w == 1) continue;
                        if (x == n || z == n || y == n || w == n) continue;
                        ans = min(ans, w1+w2+we);
                    }
                }
            }
        }
    }  

    if (ans == LINF) p(-1);
    else             p(ans);
}
