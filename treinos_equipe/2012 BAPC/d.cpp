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



ll powpow(ll a, ll b){
    if(b==0) return 1;
    ll t = powpow(a,b/2);
    t *= t;
    if(b%2) t*=a;
    return t;
}
ll firstDigit;
ll numberDigits(ll x){
    int cnt = 0;
    if(x==0) return 1;
    while(x > 0){
        firstDigit = x%10;
        x/=10;
        cnt++;
    }
    return cnt;
}

ll pegaResto(ll x){
    ll pot = 1;
    ll numero = 0;
    while(x > 10){
        numero += (x%10)*pot;
        pot *= 10;
        x /= 10;
    }
    return numero;
}

ll constroiNoves(ll x){
    ll numero = 0;
    ll pot = 1;
    fr(i, x){
        numero += 9ll*pot;
        pot*=10ll;
    }
    return numero;
    
}
ll S(ll x){
    ll nD = numberDigits(x);
    if(nD == 1) return x*(x+1ll)/2;
    ll fD = firstDigit;
    ll z = constroiNoves(nD-1ll);
    ll resto = pegaResto(x);
    ll ans = fD*S(z) + (z+1ll)*((fD-1ll)*(fD))/2ll + fD*(resto+1ll) + S(resto);
    return ans;
}



int main(){
    fastio;

    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a == 0) cout << S(b) << endl;
        else cout << S(b) - S(a-1) << endl;
    }
    

}
