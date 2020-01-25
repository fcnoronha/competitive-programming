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
    int n; scanf("%d", &n);
    ll N = n;
    ll plc = 0;
    ll ans = LINF;
    for(ll i = 1; i*i <= N; i++){
        if(n%i == 0){
            ll plc = N/i;
            for(ll j = 1; j*j <= plc; j++){
                if(plc%j == 0){
                    ll k = N/(i*j);
                    ans = min(ans, 2ll*(i*j + j*k + i*k));
                }
            }
        }
    }
    printf("%lld\n", ans);
}
