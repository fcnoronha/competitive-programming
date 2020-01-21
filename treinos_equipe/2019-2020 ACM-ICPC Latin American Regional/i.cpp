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

#define maxn 2009

const ll mod = 1000000007;

ll vis[maxn], mul[maxn], isp[maxn], cnt[maxn];
vi adj[maxn];

stack<int> st;

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;

    for (auto u: adj[v])
        dfs(u);

    st.push(v);
}

int main(){
    fastio;

    int n, l;
    cin >> n >> l;

    frr(i, l) {

        int k;
        cin >> k;

        fr(j, k) {
            int aux;
            cin >> aux;
            adj[i].pb(aux);
        }
    }

    dfs(1);
    ll b = 0, a = 0;
    for (int i = l+1; i <= n; i++) if (vis[i]) b++;

    fr(i, maxn) isp[i] = vis[i];
    
    cnt[1] = 1ll;

    while (!st.empty()) {

        int v = st.top();
        st.pop();

        for (auto u: adj[v]) {
            if (!isp[u]) continue;
            cnt[u] = (cnt[u]+cnt[v])%mod;
        }
    }

    for (int i = l+1; i <= n; i++) {
        if (!isp[i]) continue;
        a = (a + cnt[i])%mod;
    }

    cout << a << " " << b << endl;
}