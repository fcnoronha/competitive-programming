//codeforces.com/contest/1284/problem/C

#include "bits/stdc++.h"
using namespace std;

#define frr(i, n) for(int i = 1; i <= n; i++)
#define p(x) cout << x << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long int ll;

int main(){
    fastio;

    ll n, mod;
    cin >> n >> mod;

    ll fat[n+1];
    fat[0] = fat[1] = 1ll;
    frr(i, n) fat[i] = (fat[i-1]*ll(i))%mod;

    ll ans = 0ll;
    frr(k, n) {

        ll aux = (n-k+1);
        aux = (aux*aux)%mod;
        aux = (aux*fat[k])%mod;
        aux = (aux*fat[n-k])%mod;

        ans = (ans+aux)%mod;
    }

    p(ans);
}
