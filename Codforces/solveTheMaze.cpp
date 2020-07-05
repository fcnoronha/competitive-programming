//codeforces.com/contest/1365/problem/D

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

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        int grid[n][m];
        fr(i, n) {
            string s;
            cin >> s;
            fr(j, m) grid[i][j] = s[j];
        }

        int deu = 1;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        fr(i, n) fr(j, m) {
            if (grid[i][j] != 'B') continue;
            fr(k, 4) {
                int ii = i+dx[k];
                int jj = j+dy[k];
                if (ii < 0 || ii >= n) continue;
                if (jj < 0 || jj >= m) continue;
                if (grid[ii][jj] == 'G') deu = 0;
                if (grid[ii][jj] == '.') grid[ii][jj] = '#';
            }
        }

        queue<pii> q;
        q.push({n-1, m-1});
        int vis[n][m];
        ms(vis, 0);
        map<pii, bool> seen;

        while (!q.empty()) {
            pii aux = q.front();
            q.pop();

            if (seen[aux]) continue;
            seen[aux] = 1;

            int i = aux.f, j = aux.s;
            if (grid[i][j] == '#') continue;
            vis[i][j] = 1;

            fr(k, 4) {
                int ii = i+dx[k];
                int jj = j+dy[k];
                if (ii < 0 || ii >= n) continue;
                if (jj < 0 || jj >= m) continue;
                if (!seen[{ii,jj}]) q.push({ii,jj});
            }
        }

        fr(i, n) fr(j, m) {
            if (vis[i][j] == 1 && grid[i][j] == 'B') deu = 0;
            if (vis[i][j] == 0 && grid[i][j] == 'G') deu = 0;
        }

        if (deu) p("YES");
        else p("NO");
    }
}
