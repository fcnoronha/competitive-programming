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
typedef pair<pll, ll> ppll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 112345

vector< ppll > adj[maxn];

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        fr(i, n+2) adj[i].clear();

        ll k;
        cin >> k;

        fr(i, m) {
            int u, v;
            cin >> u >> v;
            ll c, w;
            cin >> c >> w;

            adj[u].pb({{c, w}, v});
            adj[v].pb({{c, w}, u});
        }

        set<ppll> st;
        st.insert({{0,0}, 1});
        vl mn_k(n+2, LINF);
        ll ans = LINF;
        while (!st.empty()) {

            auto aux = *st.begin();
            st.erase(aux);

            ll cur_w = aux.f.f;
            ll cur_cst = aux.f.s;
            int u = aux.s;

            if (cur_cst >= k) continue;
            if (cur_cst > mn_k[u]) continue;
            mn_k[u] = cur_cst; 

            if (u == n) {
                ans = cur_w;
                break;
            }

            for (auto x: adj[u]) {
                ll cst_e = x.f.f;
                ll w_e = x.f.s;
                int v = x.s;
                ll w = max(cur_w, w_e);
                ll c = cur_cst + cst_e;
                st.insert({{w, c}, v});
            }
        }

        if (ans == LINF) p(-1);
        else p(ans);
    }
}
