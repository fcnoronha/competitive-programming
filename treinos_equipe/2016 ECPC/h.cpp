#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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

int amt[12][12][12], memo[12][12][12], vis[12][12];

int main() {
    freopen("commandos.in", "r", stdin);

    int t;
    cin >> t;
    while (t--) {

        ms(amt, 0); ms(memo, 0);
        int n;
        cin >> n;

        while (n--) {
            int f, y, x, h;
            cin >> f >> y >> x >> h;
            amt[f][y][x] += h;
        }

        frr(fl, 10) {
            ms(vis, 0);
            queue<pii> q;

            q.push({10,10});
            while (!q.empty()) {
                int y = q.front().f, x = q.front().s;
                q.pop();

                if (vis[y][x]) continue;
                vis[y][x] = 1;

                if (y < 1 || y > 10 || x < 1 || x > 10) continue;
                if (fl > 1) memo[fl][y][x] = memo[fl-1][y][x];
                if (x < 10) memo[fl][y][x] = max(memo[fl][y][x], memo[fl][y][x+1]);
                if (y < 10) memo[fl][y][x] = max(memo[fl][y][x], memo[fl][y+1][x]);
                memo[fl][y][x] += amt[fl][y][x];
            
                q.push({y-1, x});
                q.push({y, x-1});
            }
        }

        p(memo[10][1][1]);
    }
}
