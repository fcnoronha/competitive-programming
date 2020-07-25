//codeforces.com/contest/1379/problem/B

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        ll l, r, m;
        cin >> l >> r >> m;

        for (ll a = l; a <= r; a++) {
            ll b = l, c = a+l-m;
            if (c >= l && c <= r) {
                cout << a << " " << b << " " << c << endl; 
                goto fim;
            }
        }

        for (ll a = l; a <= r; a++) {
            ll mod = (m%a);
            if (mod < l-r || mod > r-l) continue;
            if (m/a == 0) continue;
            ll b = r, c = r-mod;
            cout << a << " " << b << " " << c << endl; 
            goto fim; 
        }

        for (ll a = l; a <= r; a++) {
            ll mod = (m%a) - a;
            if (mod < l-r || mod > r-l) continue;
            ll b = l, c = l-mod;
            cout << a << " " << b << " " << c << endl; 
            goto fim; 
        }


        fim:;
    }
}
