//codeforces.com/contest/1200/problem/C

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main(){
    fastio

    ll n, m, q;
    cin >> n >> m >> q;

    ll g = __gcd(n, m);

    // 1 - inner
    ll bn = n/g;
    ll bm = m/g;

    // dbg(bn), dbg(bm);

    ll sx, sy, ex, ey, s1, s2;
    while (q--) {

        cin >> sx >> sy >> ex >> ey;

        if (sx == 1)
            s1 = ceil(ld(sy)/ld(bn));
        else
            s1 = ceil(ld(sy)/ld(bm));

        if (ex == 1)
            s2 = ceil(ld(ey)/ld(bn));
        else
            s2 = ceil(ld(ey)/ld(bm));

        // dbg(s1), dbg(s2);

        if (s1 == s2) p("YES");
        else p("NO");
    }
}
