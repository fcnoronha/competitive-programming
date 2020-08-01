//codeforces.com/contest/1375/problem/B

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

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;

        int g[n][m];
        fr(i, n) fr(j, m) cin >> g[i][j];

        bool deu = 1;
        fr(i, n) fr(j, m) {
            if (i == 0 || j == 0 || i == n-1 || j == m-1) {
                if ((i == 0 || i == n-1) && (j == 0 || j == m-1)) {
                    if (g[i][j] > 2) deu = 0;
                    g[i][j] = 2;
                    continue;
                }
                if (g[i][j] > 3) deu = 0;
                g[i][j] = 3;
                continue;
            }
            if (g[i][j] > 4) deu = 0;
            g[i][j] = 4;
        }

        if (!deu) {
            p("NO");
            continue;
        }

        p("YES");
        fr(i, n) {
            fr(j, m) cout << g[i][j] << " ";
            cout << endl;
        }
    }
}
