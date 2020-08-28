#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int K = 5e6 + 1;
const ll MOD = 1e9 + 7;

ll ans[K];

int main(){
    ll a, k; scanf("%lld%lld", &a, &k);
    ll sm = 0, ded = 0, base = a;
    if(a == 1ll){
        printf("1\n");
        return 0;
    }
    frr(ii, k){
        ll i = ii;
        ll plc = base - ans[i];
        plc %= MOD;
        while(plc < 0) plc += MOD;
        for(int j = 2*ii; j <= k; j+=ii){
            ans[j] += plc;
            ans[j] %= MOD;
        }
        sm += plc;
        base *= a;
        sm %= MOD;
        base %= MOD;
    }
    printf("%lld\n", (sm - ded > 0)?(sm - ded)%MOD:(sm - ded + MOD)%MOD);
}
