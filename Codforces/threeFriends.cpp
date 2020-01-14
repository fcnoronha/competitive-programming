//codeforces.com/contest/1272/problem/A

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

    ll q;
    cin >> q;

    while (q--) {

        ll v[3];
        fr(i, 3) cin >> v[i];

        ll ans = LINF;
        
        for (ll i = -1; i <= 1; i++)
            for (ll j = -1; j <= 1; j++) 
                for (ll k = -1; k <= 1; k++) {

                    ll a = v[0]+i;
                    ll b = v[1]+j;
                    ll c = v[2]+k;

                    ll aux = abs(a-b)+abs(a-c)+abs(b-c);
                    ans = min(ans, aux);
                }  

        p(ans);
    }
}
