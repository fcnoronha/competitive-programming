#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

#define maxn 11234

vi adj[maxn];
int avl[maxn], in[maxn], out[maxn];
int clk = 1;

void dfs(int u, int p) {

    out[u] = clk++;
    avl[u]--;

    int cnt = 0;
    for (auto v: adj[u]) {
        if (v == p) continue;
        cnt++;
        in[v] = out[u];
        avl[v]--;
        dfs(v, u);
    }

    if (cnt == 0) {
        out[u] = -1;
        avl[u]++;
    }

    if (avl[u] == 0) return;
    
    int v = adj[u][0];
    if (v == p) {
        if (adj[u].size() == 1) return;
        v = adj[u][1];
    }

    if (cnt > 1) {
        in[v] = in[u] = clk++;
        avl[u]--;
    }
    else if (avl[v]) {
        out[v] = in[u] = clk++;
        avl[u]--;
        avl[v]--;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n;
    cin >> n;

    fr(i, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ms(in, -1); ms(out, -1);
    frr(i, n) avl[i] = 2;

    dfs(1, 1);  

    frr(i, n) {
        if (in[i] == -1) in[i] = clk;
        if (out[i] == -1) out[i] = clk;
        cout << in[i] << ' ' << out[i] << endl;
    }
}
