//codeforces.com/contest/1388/problem/C

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

#define maxn 112345

vi adj[maxn];
ll h[maxn], p[maxn];

bool ok;

pll dfs(int u, int prt) {

    if (adj[u].size() == 1 && u != 1) {
        ll b = (p[u]-h[u])/2ll, g = p[u]-b;
        if (g < 0 || b < 0 || (g-b) != h[u]) ok = 0; 
        //cout << u << " : (" << g << " , " << b << ")\n";
        return {g, b};
    }

    pll aux = {0ll, 0ll};
    for (auto v: adj[u]) {
        if (v == prt) continue;
        pll oi = dfs(v, u);
        aux.f += oi.f, aux.s += oi.s;
    }

    ll amt = aux.s + p[u];
    if (aux.f-amt > h[u] || h[u] > aux.f+amt) ok = 0;

    //cout << u << " : (" << aux.f << " , " << aux.s << ")\n";

    if (h[u] <= 0) {
        ll aaa = aux.f - h[u];
        aux.s = aaa;
        amt -= aaa;
    }
    else {
        ll aaa = aux.f - h[u];
        aux.s = aaa;
        amt -= aaa;
    }

    if (amt%2) ok = 0;
    aux.f += amt/2ll;
    aux.s += amt/2ll;

    return aux;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;

        ok = 1;
        frr(i, n) adj[i].clear();
        frr(i, n) cin >> p[i];
        frr(i, n) cin >> h[i];

        fr(i, n-1) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(1, 1);

        if (ok) p("YES");
        else    p("NO");
    }
}
