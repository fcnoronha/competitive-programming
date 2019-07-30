//urionlinejudge.com.br/judge/en/problems/view/1576

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

    vi ans;
    vi bld[20009];
    set<pii> st;

    int maxr = 0;

    int l, h, r;
    while (cin >> l >> h >> r) {

        bld[l].pb(h);
        bld[r].pb(-h);

        maxr = max(maxr, r);
    }

    multiset<int> hs;
    hs.insert(0);

    int cur = 0;

    fr(i, maxr+3) {

        for (auto x : bld[i]) {
            if (x == 0) continue;
            if (x > 0) hs.insert(x);
            else hs.erase(hs.find(-x));
        }

        int htop = *hs.rbegin();
        if (htop != cur) {
            ans.pb(i);
            ans.pb(htop);
            cur = htop;
        }
    }

    fr(i, ans.size())
        cout << ans[i] << " \n"[i == ans.size()-1];

}
