//codeforces.com/contest/1327/problem/D

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

        int n;
        cin >> n;

        int p[n];
        fr(i, n) {
            cin >> p[i];
            p[i]--;
        }

        int c[n];
        fr(i, n) cin >> c[i];

        vi seen(n, 0);
        int ans = INF;
        fr(k, n) {

            if (seen[k]) continue;
            vi cycle;
            int v = k;
            while (!seen[v]) {
                seen[v] = 1;
                cycle.pb(v);
                v = p[v];
            }

            int m = cycle.size();
            frr(step, m+1) {

                if (m%step) continue;

                fr(s, step) {

                    bool deu = 1;
                    for (int cur = s; cur + step < m; cur += step)
                        if (c[cycle[cur]] != c[cycle[cur+step]])
                            deu = 0;

                    if (deu) {
                        ans = min(ans, step);
                        break;
                    }
                }
            }
        }

        p(ans);
    }
}
