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

#define maxn 312345

vi adj[maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, p;
    cin >> n >> p;

    map<pii, int> mp;

    fr(i, n) {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);

        mp[ { min(u,v), max(u,v) } ]++;
    }

    ll ans = 0ll, clk = 1;
    ordered_set q;
    frr(i, n) {
        // au + av >= p --> au >= p - av 
        int au = p - (int)adj[i].size();
        ans += i - 1 - (int)q.order_of_key({au, 0});
        q.insert({adj[i].size(), clk++});
    }

    for (auto x: mp) {
        int u = x.f.f, v = x.f.s;
        if (((int)adj[u].size() + (int)adj[v].size() >= p) && 
            ((int)adj[u].size() + (int)adj[v].size() - x.s < p))
            ans--;
    }

    p(ans);
}
