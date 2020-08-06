//codeforces.com/contest/1399/problem/E1

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

ll cnt[maxn], wg[maxn], sm;
vector<pll> adj[maxn];

int dfs(int u, int prt, ll amt) {
    
    if (u != 1 && adj[u].size() == 1) {
        sm += amt;
        cnt[u] = 1;
        return 1;
    }

    for (auto e: adj[u]) {
        ll v = e.f, w = e.s;
        if (v == prt) continue;
        wg[v] = w;
        cnt[u] += dfs(v, u, amt+w);
    }

    return cnt[u];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    while (t--) {
        ll n, ts;
        cin >> n >> ts;

        frr(i, n) {
            adj[i].clear();
            cnt[i] = wg[i] = 0ll;
        }
        sm = 0ll;

        fr(i, n-1) {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w}); 
        }

        dfs(1, 1, 0ll);

        set< pll > st;
        for (int i = 2; i <= n; i++) {
            ll dt = wg[i] - wg[i]/2;
            st.insert({-cnt[i]*dt, i});
        }
        
        int ans = 0;
        while (sm > ts) {   
            ans++;
            pll aux = *st.begin();
            st.erase(aux);

            ll v = aux.s, amt = -aux.s;

            ll dt = wg[v] - wg[v]/2; 
            wg[v] /= 2;

            sm -= dt*cnt[v];
            if (wg[v] == 0) continue;

            dt = wg[v] - wg[v]/2; 
            amt = cnt[v]*dt;
            st.insert({-amt, v});
        }

        p(ans);
    }
}