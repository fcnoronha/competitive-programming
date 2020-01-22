//codeforces.com/problemset/problem/830/C

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

int main(){
    fastio;

    ll n, k;
    cin >> n >> k;

    ll a[n];
    fr(i, n) cin >> a[i];

    ll sm = 0ll;
    fr(i, n) sm += a[i];

    ll s = sm+k, ans = 0;
    for (ll d = 1ll; d*d <= s; d++) {

        ll d1 = s/d;
        ll aux = 0ll;
        fr(i, n) aux += (a[i]+d1-1)/d1;

        aux = s/aux; 
        if (aux == d1) ans = max(ans, d1);

        d1 = d;
        aux = 0ll;
        fr(i, n) aux += (a[i]+d1-1)/d1;

        aux = s/aux; 
        if (aux == d) ans = max(ans, d);
    }

    p(ans);
}
