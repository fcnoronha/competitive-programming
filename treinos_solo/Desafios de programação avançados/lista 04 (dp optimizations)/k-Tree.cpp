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

const ll mod = 1000000007;

ll memo[112][2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    ll n, k, d;
    cin >> n >> k >> d;

    memo[0][0] = 1;

    for (int i = 0; i <= n; i++) {

        for (int j = 1; j+i <= n && j <= k; j++) {
            
            if (j < d) {
                memo[i+j][0] = (memo[i+j][0] + memo[i][0])%mod;
                memo[i+j][1] = (memo[i+j][1] + memo[i][1])%mod;
                continue;
            }

            memo[i+j][1] = (memo[i+j][1] + memo[i][0])%mod;
            memo[i+j][1] = (memo[i+j][1] + memo[i][1])%mod;
        }
        // dbg(memo[i][1]);
    }

    p(memo[n][1]);
}
