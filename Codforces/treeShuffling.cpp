//codeforces.com/contest/1363/problem/E

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

#define maxn 212345

vi adj[maxn];
ll a[maxn], b[maxn], c[maxn];
ll ans;

pll dfs(int u, int p, ll cst) {

    pll cnt = {0ll, 0ll};
    for (auto v: adj[u]) 
        if (v != p) {
            pll plc = dfs(v, u, min(cst, a[u]));
            cnt.f += plc.f, cnt.s += plc.s;
        }
    if (b[u] != c[u]) {
        cnt.f += (b[u]);
        cnt.s += !(b[u]);
    }
    
    if (a[u] <= cst) {
        ll oi = min(cnt.f, cnt.s);
        cnt.f -= oi, cnt.s -= oi;
        ans += a[u]*oi*2ll;
    }
    return cnt;
}

int main() {
    fastio;

    int n;
    cin >> n;

    frr(i, n) cin >> a[i] >> b[i] >> c[i];
    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    auto aux = dfs(1, 1, a[1]);
    if (aux.f || aux.s) p(-1);
    else                p(ans);
}
