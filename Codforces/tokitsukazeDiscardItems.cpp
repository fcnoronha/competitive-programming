//codeforces.com/contest/1191/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio

    ll n, m, k;
    cin >> n >> m >> k;

    ll p[m];
    fr(i, m) cin >> p[i];


    ll ans = 0ll, tk = 0ll, act_pg = (p[0]-1ll)/k;
    ll i = 0ll;
    while (i < m) {

        ll ac = 0ll;

        act_pg = max( (p[i]-tk-1ll)/k, act_pg);

        while ( i < m && (p[i]-tk-1ll)/k == act_pg ) {

            ac++;
            i++;
        }

        tk += ac;
        ans++;
    }

    p(ans);
}
