//www.spoj.com/problems/CERC07K/

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

// Just a normal bfs, but with the mask of the keys I have.

int main(){
    fastio

    // Because fuck you SPOJ. What does it cost to make a more simplified input?
    map<char, int> mp;
    mp['#'] = -1;
    mp['.'] = 0;
    mp['*'] = 6969;
    // FUCKING DOORS
    mp['B'] = 1;
    mp['Y'] = 2;
    mp['R'] = 3;
    mp['G'] = 4;
    // FUCKING KEYS
    mp['b'] = 5;
    mp['y'] = 10;
    mp['r'] = 15;
    mp['g'] = 20;
    mp['X'] = 420;

    int r, c;
    while (cin >> r >> c && r && c) {

        // {{mask, cnt}, {i, j}}
        queue< pair< pii, pii > > bfs;

        int grid[r][c];
        fr(i, r) {
            string x;
            cin >> x;
            fr(j, c) {
                grid[i][j] = mp[x[j]];

                if (grid[i][j] == 6969)
                    bfs.push({{0, 0}, {i, j}});
            }
        }

        /*
        fr(i, r) {
            fr(j, c)
                cout << grid[i][j];
            cout << endl;
        }
        */

        bool vis[(1<<6)][r][c];
        ms(vis, 0);
        int ans = INF;
        while (!bfs.empty()) {

            int i = bfs.front().s.f;
            int j = bfs.front().s.s;
            int mask = bfs.front().f.f;
            int cnt = bfs.front().f.s;
            bfs.pop();

            if (i < 0 || i >= r || j < 0 || j >= c)
            continue;

            if (vis[mask][i][j]) continue;
            vis[mask][i][j] = 1;


            if (grid[i][j] == 420) {
                ans = min(ans, cnt);
                continue;
            }

            if (grid[i][j] == -1)
                continue;

            bool faco_o_urro = 0;

            if (grid[i][j] == 0 || grid[i][j] == 6969) {
                faco_o_urro = 1;
            }

            else if (grid[i][j] >= 5 && grid[i][j] <= 20) {
                faco_o_urro = 1;
                mask |= (1<<(grid[i][j]/5));
            }

            else if (grid[i][j] >= 1 && grid[i][j] <= 4 && (mask&(1<<grid[i][j]))) {
                faco_o_urro = 1;
            }

            if (!faco_o_urro) continue;

            vector<pii> oi = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto p : oi) {

                int ni = i + p.f;
                int nj = j + p.s;

                bfs.push({{mask, cnt+1}, {ni, nj}});
            }
        }

        if (ans < INF)
            cout << "Escape possible in " << ans << " steps.\n";
        else
            cout << "The poor student is trapped!\n";

    }
}
