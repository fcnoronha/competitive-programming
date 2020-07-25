//codeforces.com/contest/1359/problem/C

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

        ll h, c, t;
        cin >> h >> c >> t;

        if (h+c >= 2*t) {
            p(2);
            continue;
        }

        ll k1 = (h-t)/(-c-h+t+t);
        ll k2 = k1+1;
        ll k;
        
        ll a1 = abs( k1*(h+c)+h - t*(k1+k1+1))*(k2+k2+1);
        ll a2 = abs( k2*(h+c)+h - t*(k2+k2+1))*(k1+k1+1);
        if ( a1 <= a2 ) k = k1;
        else           k = k2; 

        p((2*k)+1);
    }
}
