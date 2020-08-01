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

#define maxn 250123

set< pair< pair<ll, int>, int >> st; // {{dist, v_ori}, v}
pair<int, ll> memo[maxn]; // {ori, dist} to vertice v
vector<pii> adj[maxn];
double ans[maxn];
bool seen[maxn];
pii endp[maxn]; 
ll w[maxn];
vi kct;

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    fr(i, m) {
        int u, v, wg;
        cin >> u >> v >> wg;
        adj[u].pb({v, wg});
        adj[v].pb({u, wg});
        w[i] = ll(wg);
        endp[i] = {u, v};
    }

    int k;
    cin >> k;
    fr(i, k) {
        int v;
        cin >> v;
        kct.pb(v);
        st.insert({{0ll, v}, v});
    }

    while (!st.empty()) {

        auto x = *st.begin();
        st.erase(x);

        ll curd = x.f.f;
        int ori = x.f.s, u = x.s;

        if (seen[u]) continue;
        seen[u] = 1;
        memo[u] = {ori, curd};

        for (auto edg: adj[u]) {
            int v = edg.f;
            ll w = edg.s;
            if (seen[v]) continue;
            st.insert({{curd+w, ori}, v});
        }
    }

    fr(i, m) {
        int u = endp[i].f, v = endp[i].s;

        if (memo[u].f == memo[v].f) {
            ans[memo[u].f] += double(w[i]);
            continue;
        }

        int ou = memo[u].f, ov = memo[v].f;
        ll  du = memo[u].s, dv = memo[v].s;

        if (dv > du) {
            swap(du, dv);
            swap(ou, ov);
        }

        ll d = du-dv;
        ans[ov] += double(d) + double(w[i]-d)/2.0;
        ans[ou] += double(w[i]-d)/2.0;
    }

    for (auto v: kct) 
        cout << setprecision(1) << fixed << ans[v] << endl;
}
