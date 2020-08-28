//codeforces.com/contest/1400/problem/D

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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int t;
    cin >> t;
    while (t--) {
        
        ll n;
        cin >> n;

        ll a[n+2];
        frr(i, n) cin >> a[i], a[i]--;

        ll mpl[n+2][n], mpr[n+2][n];
        ms(mpl, 0ll); ms(mpr, 0ll);

        frr(i, n) {
            mpl[i][a[i]]++;
            fr(j, n) mpl[i][j] += mpl[i-1][j];
        }

        for (int i = n; i > 0; i--) {
            mpr[i][a[i]]++;
            fr(j, n) mpr[i][j] += mpr[i+1][j];
        }

        ll ans = 0ll;
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                ans += mpl[i-1][a[j]]*mpr[j+1][a[i]];
            }
        }

        p(ans);
    }
}
