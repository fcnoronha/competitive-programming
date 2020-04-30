//codeforces.com/contest/1337/problem/C

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
ll lvl[maxn], deg[maxn], tp[maxn], prt[maxn], blw[maxn];
ll ans;

ll dfs(int u, int p, ll l) {
    lvl[u] = l;
    prt[u] = p;
    for (auto v: adj[u])
        if (v != p) {
            blw[u] += dfs(v, u, l+1);
            deg[u]++;
        }
    return blw[u]+1;
}

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 1, 0);
    //frr(i, n) cout << "u: " << i << "|blw[u]: " << blw[i] << endl;

    set< pll > st;
    frr(i, n) if (deg[i] == 0) st.insert({-(lvl[i]), i});
    fr(i, k) {
        auto aux = *st.begin();
        st.erase(aux);
        ans -= aux.f;

        int u = aux.s;
        tp[u] = 1;
        deg[prt[u]]--;
        if (deg[prt[u]]) continue;
        
        ll amt = lvl[prt[u]] - blw[prt[u]];
        st.insert({-amt, prt[u]});
    }

    p(ans);
}
