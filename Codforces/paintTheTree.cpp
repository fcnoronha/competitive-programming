//codeforces.com/contest/1244/problem/D

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

int main(){
    fastio;

    ll n;
    cin >> n;

    vl adj[n];
    ll cost[n][3];
    fr(c, 3)
        fr(i, n)
            cin >> cost[i][c];

    ll u, v;
    fr(i, n-1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll root;
    fr(i, n) {

        if (adj[i].size() > 2) {
            cout << "-1\n";
            return 0;
        }

        if (adj[i].size() == 1)
            root = i;
    }

    ll ans_mn = LLONG_MAX;
    vl ans_v;
    int col[3] = {0, 1, 2};

    do {

        ll u = root;
        ll v = adj[u][0];
        vl order(n);

        fr(i, n-2) {
            int next = adj[v][0];
            if (next == u) next = adj[v][1];

            order[u] = i;
            u = v;
            v = next;
        }
        order[u] = n-2;
        order[v] = n-1;

        ll t_cost = 0ll;
        fr(i, n) {
            ll c_idx = col[order[i]%3];
            order[i] = c_idx;
            t_cost += cost[i][c_idx];
        }

        if (t_cost < ans_mn) {
            ans_mn = t_cost;
            ans_v = order;
        }

    } while (next_permutation(col, col+3));

    cout << ans_mn << endl;
    for (auto c : ans_v)
        cout << c+1 << " ";
    cout << endl;
}
