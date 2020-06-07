//codeforces.com/contest/19/problem/E

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

#define maxn 11234

int n, m;
vector<pii> adj[maxn];
int col[maxn], h[maxn], cntc;
int cnti[maxn], cntp[maxn];
int vcnti[maxn], vcntp[maxn];

void dfs(int u, int p) {

    for (auto aux: adj[u]) {
        int v = aux.f, eid = aux.s;

        if (v == p) continue;
        if (col[v] == -1) {
            h[v] = h[u] + 1;
            col[v] = !col[u];
            dfs(v, u);

            vcnti[u] += vcnti[v], vcntp[u] += vcntp[v];
            cnti[eid] = vcnti[v], cntp[eid] = vcntp[v];
            continue;
        } 
        
        if (h[v] > h[u]) continue;
        if (col[v] == col[u]) {
            cntc++;
            cnti[eid]++;
            vcnti[v]--;
            vcnti[u]++;
            continue;
        }
        if (col[v] != col[u]) {
            cntp[eid]++;
            vcntp[v]--;
            vcntp[u]++;
            continue;
        }
    }
}

int main() {
    fastio;

    cin >> n >> m;
    fr(i, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i+1});
        adj[v].pb({u, i+1});
    }

    ms(col, -1);
    frr(i, n) {
        if (col[i] != -1) continue;
        col[i] = 0;
        dfs(i, i);
    }

    if (cntc == 0) {
        p(m);
        frr(i, m) cout << i << " \n"[i == m];
        return 0;
    }

    vi ans;
    frr(i, m) 
        if (cnti[i] == cntc && cntp[i] == 0) 
            ans.pb(i);
    p(ans.size());
    pv(ans);
}
