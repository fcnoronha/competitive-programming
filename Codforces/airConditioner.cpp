//codeforces.com/contest/1304/problem/C

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

    int q;
    cin >> q;

    while (q--) {

        ll n, m;
        cin >> n >> m;

        int deu = 1;
        ll t, l, h, lst = 0ll;

        pll rg = {m, m};

        while (n--) {

            cin >> t >> l >> h;

            if (!deu) continue;

            ll d = t - lst;
            rg.f -= d;
            rg.s += d; 

            if (rg.f > h || rg.s < l) {
                deu = 0;
                continue;
            }

            rg.f = max(rg.f, l);
            rg.s = min(rg.s, h);
            lst = t;
        }

        if (deu) p("YES");
        else p("NO");
    }
}
