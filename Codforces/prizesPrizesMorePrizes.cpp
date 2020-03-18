//codeforces.com/contest/208/problem/D

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

int main() {
    fastio;

    int n;
    cin >> n;

    vl v(n);
    fr(i, n) cin >> v[i];
    vl price(5), cnt(5, 0);
    fr(i, 5) cin >> price[i];
    
    ll amt = 0ll;
    for (ll x: v) {
        amt += x;
        for (int i = 4; i >= 0; i--) {
            if (price[i] > amt) continue;
            cnt[i] += amt/price[i];
            amt %= price[i];
        }
    }

    pv(cnt);
    p(amt);
}
