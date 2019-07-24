//www.spoj.com/problems/RIOI_2_3/

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

int main(){
    fastio

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // {{mask, cnt}, {i, j}}
        queue< pair< pii, pii > > bfs;

        int grid[n][n];
        fr(i, n)
            fr(j, n)
                cin >> grid[i][j];

        bool vis[(1<<11)][n][n];
        ms(vis, 0);
        int ans = INF;

        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        bfs.push({{0, 0}, {sx, sy}});

        while (!bfs.empty()) {

            int i = bfs.front().s.f;
            int j = bfs.front().s.s;
            int mask = bfs.front().f.f;
            int cnt = bfs.front().f.s;
            bfs.pop();

            if (i < 0 || i >= n || j < 0 || j >= n)
                continue;

            if (vis[mask][i][j]) continue;
                vis[mask][i][j] = 1;
            
            if (!(mask & (1<<grid[i][j]))) {
                cnt++;
                mask |= (1<<grid[i][j]);
            }

            if (i == ex && j == ey) {
                ans = min(ans, cnt);
                continue;
            }

            vector<pii> oi = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto p : oi) {

                int ni = i + p.f;
                int nj = j + p.s;

                bfs.push({{mask, cnt}, {ni, nj}});
            }
        }

        p(ans);

    }
}
