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

#define maxn 1000056

vi adj[maxn];
int sz[maxn], mp[maxn];

int dfs(int u, int prt) {  

    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == prt) continue;
        sz[u] += dfs(v, u);
    }

    mp[sz[u]]++;
    return sz[u];
}

int main() {

    fastio;

    int n;
    cin >> n;

    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,1);

    for (int c = (n+1)/2; c > 0; c--) {

        int cnt = 0;
        for (int i = c; i <= n; i += c) cnt += mp[i];
        //cout << "c: " << c << " cnt: " << cnt << endl;
        if (n == cnt*c) cout << (n/c) - 1 << " ";
    }
    cout << endl;
}
