//codeforces.com/contest/1230/problem/C

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

vi adj[10];
int deg[10];

int main(){
    fastio

    int n, m;
    cin >> n >> m;

    int u,v;
    fr(i, m) {
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[v]++;
        deg[u]++;
    }

    if (n < 7) {
        cout << m << "\n";
        return 0;
    }

    int ans = 0;
    fr(i, n) {
        fr(j, n) {

            if (i == j) continue;

            int aux = m - adj[i].size() - adj[j].size();
            int used = 0;

            for (auto x : adj[i]) used |= (1<<x);
            for (auto x : adj[j]) used |= (1<<x);

            aux += __builtin_popcount(used);
            ans = max(ans, aux);
        }
    }

    cout << ans << endl;
}
