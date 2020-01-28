#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll cap[100009], pour[100009];

int main(){
	fastio

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        fr(i, n+2) pour[i] = 0LL;

        fr(i, n)
            cin >> cap[i];

        ll x, y;
        fr(i, m) {
            cin >> x >> y;

            x--;
            pour[x] += y;
        }

        ll ac = 0LL;
        fr(i, n) {

            pour[i] += ac;
            ac = 0LL;

            if (pour[i] > cap[i]) {
                ac = pour[i]-cap[i];
                pour[i] = cap[i];
            }
        }

        p(ac);
        fr(i, n) cout << pour[i] << " \n"[i == n-1];
    }
}
