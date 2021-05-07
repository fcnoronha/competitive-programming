#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

ll memo[1123][1123];
int opt[1123][1123];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n, m;
    while (cin >> n >> m) {

        vl brk(m+2);
        frr(i, m) cin >> brk[i];
        brk[0] = 0;
        brk[m+1] = n;

        // pv(brk);
        for (int lg = 0; lg <= m+1; lg++) {

            for (int l = 0; l+lg-1 <= m; l++) {

                int r = l+lg;

                if (lg < 2) {
                    memo[l][r] = 0;
                    opt[l][r] = l;
                    continue;
                }
                
                memo[l][r] = LINF;
                for (int k = opt[l][r-1]; k <= opt[l+1][r]; k++) {
                    
                    ll cst = brk[r]-brk[l];
                    // if (cst < 0) {
                    //     dbg(brk[r]);
                    //     dbg(cst);
                    // }

                    ll aux = memo[l][k]+memo[k][r] + cst;
                    if (memo[l][r] > aux) {
                        memo[l][r] = aux;
                        opt[l][r] = k;
                    }
                }
            }
        }

        p(memo[0][m+1]);
    }
}
