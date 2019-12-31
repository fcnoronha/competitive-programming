//codeforces.com/contest/1253/problem/D

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

#define maxn 200009

vi adj[maxn];
int l, r, mxr, vis[maxn];

void dfs(int v) {

    if (vis[v]) return;
    vis[v] = 1;

    l = min(l, v);
    r = max(r, v);

    for (auto u: adj[v]) dfs(u);
}

int main(){
    fastio;

    int n, m;
    cin >> n >> m;

    int u, v;
    fr(i, m) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = 0;
    frr(i, n) {

        if (vis[i]) continue;
        l = r = i;
        dfs(i);

        if (l <= mxr) 
            ans++;
        
        mxr = max(mxr, r);
    }

    p(ans);
}
