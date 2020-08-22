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

long double k, p, x;

long double f(ll m) {
    long double mm = (long double)m;
    long double ret = (m*m*x + p*k)/m;
    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    cin >> k >> p >> x;

    ll l = 1ll, r = INF;
    long double ans = 10e18;
    fr(kkk, 100) {
        ll m1 = l + (r-l) / 3;
        ll m2 = r - (r-l) / 3;
        long double f1 = f(m1);   
        long double f2 = f(m2);     
        ans = min({ans, f1, f2});
        // Change if wants minimum
        if (f1 > f2) l = m1;
        else		 r = m2;
    }
    
    cout << setprecision(3) << fixed << ans << endl;
}
