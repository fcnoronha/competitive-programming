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
#define maxn 1000009

vl isPrime(maxn, true);
vl primes;
vl SPF(maxn);

int main(){
    fastio;

    ll a, b;
    cin >> a >> b;

    vl ans;
    for (ll x = 1ll; x*x <= a; x++) {
            if (a%x != 0) continue;
            if (x%b == 0) ans.pb(x);
            if (x*x != a && (a/x)%b == 0) ans.pb(a/x);
        }
    
    sort(all(ans));
    pv(ans);
}
