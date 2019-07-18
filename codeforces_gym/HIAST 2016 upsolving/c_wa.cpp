//codeforces.com/gym/101061

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

// {pedestrian_distance, total_distance}
pll adj[103][103];

pll operator+(pll a, pll b) {
    return {a.f+b.f, a.s+b.s};
}

int main(){
	fastio

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        frr(i, n) frr(j, n) adj[i][j] = {INT_MAX, INT_MAX};

        ll a, b, c, k;
        fr(i, m) {

            cin >> a >> b >> c >> k;

            pll aux = {INT_MAX, INT_MAX};

            if (k == 1ll) {
                aux = {c, c};

                if (adj[a][b].f == 0ll) continue;
            }
            else
                aux = {0ll, c};

            adj[a][b] = min(adj[a][b], aux);
            adj[b][a] = min(adj[b][a], aux);
        }

        frr(k, n)
        	frr(i, n)
        		frr(j, n)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        int x, y;
        cin >> x >> y;

        if (adj[x][y].s >= INT_MAX || adj[x][y].f >= INT_MAX) {
            p("-1");
            return 0;
        }

        cout << adj[x][y].f << " " << adj[x][y].s << '\n';
    }
}
