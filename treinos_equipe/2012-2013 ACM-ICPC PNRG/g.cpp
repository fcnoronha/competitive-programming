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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

ll n;
map<pll,ll> memo;
map<pll,ll> vis;
//
// ll choose(int i, int j){
//     return memo[i][j];
// }

ll solve(ll x, ll falta){

    if(falta==0)
        return 1;

    if(x==0)
        return 0;

    if(vis[{x,falta}])
        return memo[{x,falta}];

    ll ligado = 63 - __builtin_clzll(x);

    //escolhe pegar o bit ligado

    vis[{x,falta}]=1;
    ll ans = 0;

    ll desliga = x^(1ll<<ligado);
    ans+= solve(desliga, falta-1);

    //escolhe passar

    ll cacete = (1ll<<ligado)-1ll;
    ll tenho = __builtin_popcount(cacete);

    ans+=solve(cacete,falta);

    return memo[{x,falta}]=ans;

}

int main(){
    fastio;

    // frr(i,60){
    //     memo[i][1]=i;
    //     memo[i][0]=1;
    // }
    // for(ll i=1;i<=60;i++){
    //     for(ll j=1;j<i;j++){
    //         memo[i][j+1]=memo[i][j]*(i-j)/(j+1ll);
    //     }
    // }

    while(cin>>n){
        ll ans = 0;
        for(ll i=3;i<=60;i+=3)
            ans+=solve(n,i);
        cout << "Day " << n << ": Level = " << ans << endl;
    }
}
