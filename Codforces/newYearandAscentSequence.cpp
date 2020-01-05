//codeforces.com/contest/1284/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(),x.end()
#define p(x) cout << x << "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define s second
#define f first

typedef long long int ll;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;

int main(){
    fastio;

    int n;
    cin >> n;

    vector<pll> ac;

    ll ans = 0ll;
    ll foi = 0ll;

    fr(i, n) {

        ll l, mn = INF, mx = -1, aux;
        cin >> l;
        
        ll tem = 0ll;
        fr(j, l) {
            
            cin >> aux;

            if (aux > mn) tem = 1;

            mn = min(mn, aux);
            mx = max(mx, aux);
        }
        if (!tem) ac.pb({mn, mx});
        else {
            ans += ((2*n)-1) - 2*foi;
            foi++;
        }
    }

    sort(all(ac));

    fr(i, ac.size()) {
        ll mx = ac[i].s;
        ll amt = (upper_bound(all(ac), pll(mx-1, INF)) - ac.begin());
        ans += amt;
    }

    p(ans);
}
