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
#define rvr(x) int x; scanf("%d", &x)


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int freq[30];

int main(){

    rvr(t);

    while (t--) {

        rvr(p); rvr(n);

        vi adj(p, 0);

        fr(i, n) {

            rvr(u); rvr(v);

            u--, v--;
            adj[u] |= (1<<v);
        }

        int ans = p;
        fr(i, (1<<p)) {

            fr(i, p) freq[i] = 0;
            int cntb = 0, cntg = (1<<p)-1;

            fr(j, p) {

                if (!(i & (1<<j))) continue;

                cntb++;
                cntg &= adj[j];
            }

            cntg = __builtin_popcount(cntg);

            ans = max(ans, cntb+cntg);
        }

        printf("%d\n", ans);
    }
}
