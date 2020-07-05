//codeforces.com/contest/1366/problem/C

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
typedef vector<pii> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int grid[n][m];
        fr(i, n) fr(j, m) cin >> grid[i][j];

        vi dist(n+m, {0,0});
        fr(i, n) fr(j, m) {
            if (grid[i][j]) dist[i+j].f++;
            else            dist[i+j].s++;
        }

        int ans = 0;
        fr(i, n+m-1) {
            int j = n+m-2-i;
            if (i <= j) continue;
            ans += min(dist[i].s+dist[j].s, dist[i].f+dist[j].f);
        }

        p(ans);
    }
}
