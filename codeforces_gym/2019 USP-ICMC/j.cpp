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

int isP(ll x) {
    if (x == 1) return false;
    for (ll i = 2; i*i <= x; i++)
        if (x%i == 0) return false;
    return true;
}

int main(){
    fastio;

    int n;
    cin >> n;

    vl v(n);
    for (auto &x : v) cin >> x;
    
    sort(all(v));
    ll meio = v[n/2], mx, mn;

    mx = meio;
    while (!isP(mx)) mx++;
    
    mn = meio;
    while (mn >= 2 && !isP(mn)) mn--;
    
    ll ans = LINF, aux = 0ll;
    for (auto x : v) {
        aux += abs(x-mx);
    }

    if (mn >= 2) {
        ans = 0ll;
        for (auto x: v) 
            ans += abs(x-mn);
    }

    ans = min(ans, aux);
    p(ans);
}   
