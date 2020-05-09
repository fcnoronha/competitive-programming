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
typedef pair<ld, int> pli;

#define maxn 109
const ld INF = 10000000000000000000.0;
const ld EPS = 0.0000000001;

vector<pii> adj[maxn];
bool is_exit[maxn], seen[maxn];
ld dp[maxn], db[maxn];

int solve(ld vel, int n, int b) {

    frr(i, n) {
        seen[i] = 0;
        db[i] = INF;
    }

    set< pli > st;
    st.insert({0.0, b});
    db[b] = 0.0;
    while(!st.empty()) {
        pli aux = *st.begin(); st.erase(aux);

        int u = aux.s;
        if (is_exit[u]) return 1;
        ld dis = db[u];

        if (seen[u]) continue;
        seen[u] = 1;

        for (auto x: adj[u]) {
            int v = x.f;
            if (seen[v]) continue;
            ld l = (ld)x.s;
            ld ndis = dis + (l/vel);
            if (dp[v]-ndis > EPS && db[v]-ndis > EPS) {
                db[v] = ndis;
                st.insert({ndis, v});
            }
        }
    }
    return 0;
}

int main() {
    //fastio;
    cout << setprecision(10) << fixed;

    int n, m, e;
    cin >> n >> m >> e;

    fr(i, m) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].pb({v, l});
        adj[v].pb({u, l});
    }

    fr(i, e) {
        int u;
        cin >> u;
        is_exit[u] = 1;
    }

    frr(i, n) dp[i] = db[i] = INF;

    int b, p;
    cin >> b >> p;

    set< pli > st;
    st.insert({0.0, p});
    dp[p] = 0.0;
    while(!st.empty()) {
        pli aux = *st.begin();
        st.erase(aux);

        int u = aux.s;
        ld dis = dp[u];
        
        if (seen[u]) continue;
        seen[u] = 1;

        for (auto x: adj[u]) {
            int v = x.f;
            if (seen[v]) continue;
            ld l = (ld)x.s;
            ld ndis = dis + ((ld)l/160.0);
            if (dp[v]-ndis > EPS) {
                dp[v] = ndis;
                st.insert({ndis, v});
            }
        }
    }

    int deu = 0;
    ld lo = EPS, hi = INF;
    fr(kk, 200) {
        ld mid = (lo+hi)/2.0;
        
        if (solve(mid, n, b)) hi = mid, deu = 1;
        else lo = mid;
    }

    if (deu) cout << lo << endl;
    else cout << "IMPOSSIBLE\n";
}