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

vi poss[109];
bool vis[109];
int matchR[109];

bool bpm(int u) {

    for (auto v : poss[u]) {

        if (vis[v]) continue;
        vis[v] = true;

        if (matchR[v] < 0 || bpm(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int maxBPM(int n) {

    memset(matchR, -1, sizeof(matchR));

    int ans = 0;
    for (int u = 0; u < n; u++) {

        memset(vis, 0, sizeof(vis));

        if (bpm(u))
            ans++;
    }
    return ans;
}

int main() {
	fastio

    int t;
    cin >> t;

    while (t--) {

        int n, m, w;
        cin >> n >> m >> w;

        vi gosta_l[n];
        fr(i, n) {

            int y, aux;
            cin >> y;

            while (y--) {
                cin >> aux;
                gosta_l[i].pb(aux);
            }
        }

        vi gosta_a[n];
        fr(i, n) {

            int y, aux;
            cin >> y;

            while (y--) {
                cin >> aux;
                gosta_a[i].pb(aux);
            }
        }

        vi armas_disp[m+1];
        frr(i, m) {

            int y, aux;
            cin >> y;

            while (y--) {
                cin >> aux;
                armas_disp[i].pb(aux);
            }

            sort(all(armas_disp[i]));
        }

        // Real possiblities for a guard to be
        fr(i, n) {

            poss[i].clear();

            for( auto l : gosta_l[i] ) {

                for ( auto a : gosta_a[i] ) {

                    if (binary_search(all(armas_disp[l]), a)) {
                        poss[i].pb(l);
                        break;
                    }
                }
            }
        }

        // Ford-Fulkerson algorithm 
        p(maxBPM(n));
    }
}
