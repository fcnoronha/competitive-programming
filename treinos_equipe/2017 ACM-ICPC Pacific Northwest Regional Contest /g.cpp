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
 
#define maxn 1123
 
vector<pii> adj[maxn];
pii lmt[5*maxn];
 
int vis[maxn];
int clk = 1, s, t;    
 
bool dfs(int u, int bit) {
 
    if (vis[u]) return 0;
    vis[u] = 1;
 
    if (u == t) return 1;
 
    bool deu = 0;
    for (auto x: adj[u]) {
        int v = x.f, j = x.s;
        if (lmt[j].f <= bit && bit <= lmt[j].s)
            deu |= dfs(v, bit);
    }
 
    return deu;
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;
 
    int n, m, k;
    cin >> n >> m >> k; 
    cin >> s >> t;
 

    vector<int> st;
    frr(i, m) {
        int a, b;
        cin >> a >> b >> lmt[i].f >> lmt[i].s;
        adj[a].pb({b,i});
        st.pb(lmt[i].f-1);
        st.pb(lmt[i].s);
    }
    sort(all(st));
    int ans = 0;
    for (int i = 1; i<st.size(); i++) {
        int b = st[i];
        ms(vis, 0);
        if (dfs(s, b)) {
            ans += st[i]-st[i-1];
        }
    }
    p(ans);
}