//codeforces.com/contest/1303/problem/B

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

    int t;
    cin >> t;

    while (t--) {

        ll n, g, b;
        cin >> n >> g >> b; 

        ll hf = (n+1ll)/2;
        ll ans = 0ll;

        ll aux = (n/(g+b))*g + min(g, (n%(g+b)));
        if (aux >= hf) {
            p(n);
            continue;
        }

        ll lo = n, hi = LLONG_MAX;
        fr(i, 100) {

            ll m = lo + (hi-lo)/2;
            aux = (m/(g+b))*g + min(g, (m%(g+b)));
            if (aux >= hf) hi = m-1, ans = m;
            else lo = m+1;
        }

        p(ans);
    }
}
