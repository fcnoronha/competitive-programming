#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(iii, x.size()) cout << x[iii] << " \n"[iii==x.size()-1]
#define pvv(x, n) for(int iii = 1, vaca = nnn; i <= nnn;i++) cout << x[i] << " \n"[iii==nnn];

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
const int N = 1e6 + 1;

ll v[1000005];
ll z[1000005];
vector<ll> A;
vector<ll> B;
int main(){
    fastio;
    ll n;
    cin >> n;
    fr(i,n) cin >> v[i];
    z[0] = 0;
    fr(i,n){
        z[i+1] =  v[i] - z[i];
    }

    for(int i = 0; i<n+1; i += 2) A.pb(z[i]);
    for(int i = 1; i<n+1; i += 2) B.pb(z[i]);

    ll a = -(*min_element(all(A)));
    ll b = *min_element(all(B));
    cout << max(0ll, b-a+1ll) << endl;

}
