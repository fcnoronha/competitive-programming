//codeforces.com/contest/1281/problem/C

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

const ll mod = 1000000007ll;

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        int x;
        string s;
        cin >> x >> s;

        ll ans = ll(s.size());
        for (ll i = 1ll; i <= x; i++) {
            
            ll n_vez = ll(s[i-1]-49ll);

            if ((ll)s.size() <= x) {
                
                ll s_size = ll(s.size());
                fr(add, n_vez) 
                    for (int j = i; j < s_size; j++) s += s[j];

                ans = (ll(s.size()))%mod;
                continue;
            }
            
            ll aux = (ans - i + mod)%mod;
            ans = (ans +   (n_vez*aux) % mod     )%mod;
        } 

        p(ans);
    }
}
