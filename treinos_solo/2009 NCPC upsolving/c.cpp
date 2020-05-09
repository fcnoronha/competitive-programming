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

int memo[(1<<21)][10], d[30];

int main() {
    fastio;

    ms(memo, INF);
    memo[0][0] = 0;
    
    int n;
    cin >> n;
    fr(i, n) cin >> d[i];

    for (int mask = 1; mask < (1<<n); mask++) {
        fr(j, n) {
            if (((1<<j)&mask) == 0) continue;
            fr(old, 7) {
                int psbl = max(d[j]-old-1, 0);
                int &pdm = memo[mask][psbl]; 
                pdm = min(pdm, memo[mask-(1<<j)][old] + psbl + 1);  
            }
        }
    }

    int ans = INF;
    fr(k, 7) ans = min(ans, memo[(1<<n)-1][k]);
    p(ans);
}
