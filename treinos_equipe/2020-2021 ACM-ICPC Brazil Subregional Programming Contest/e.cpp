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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds ;
typedef tree< pii, null_type,less< pii >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set ql, qr;
// int idx = q.order_of_key(val) // number of elements STRICT LESS than val

#define maxn 112345

int ida[maxn], l[maxn], r[maxn], ans[maxn], clk1 = 3, clk2 = 3;
vi adj[maxn], radj[maxn];

set<int> host[maxn];
set<pii> lft;

void dfs_sobe(int u) {

    for (auto v: adj[u]) {
        if (v == u) continue;
        dfs_sobe(v);
    }

    if (u == 1) {
        for (auto x: lft) 
            host[u].insert(x.s);
        return;
    }
    
    for (auto x: host[u]) lft.insert({r[x], x});
    host[u].clear();

    int ipa = ida[radj[u][0]];
    vector<pii> aux;
    for (auto x: lft) {
        if (x.f >= ipa) break;
        aux.pb(x);
    }

    for (auto x: aux) {
        lft.erase(x);
        host[u].insert(x.s);
    }
}

void dfs(int u) {

    // numero que hosteia
    ans[u] = host[u].size();

    // numero de ls menor que eu
    ans[u] += ql.order_of_key({ida[u], INF});

    // colocando l
    vector<pii> aux;
    for (auto x: host[u]) {
        aux.pb({l[x], clk1});
        ql.insert({l[x], clk1++});
    }

    for (int v: adj[u]) {
        if (v==u) continue;
        dfs(v);
    }

    // tirando l
    for (auto x: aux) ql.erase(x);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, m;
    cin >> n >> m;
    

    frr(i, n) {
        int idade, x;
        cin >> idade >> x;
        ida[i] = idade;
        radj[i].pb(x);
        adj[x].pb(i);
    }

    //frr(j, n) pv(adj[j]);
    //return 0;

    fr(i, m) {
        int oj;
        cin >> oj >> l[i] >> r[i];
        host[oj].insert(i);
    }

    dfs_sobe(1);
    dfs(1);
    frr(i, n) cout << ans[i] << " \n"[i==n];
}
