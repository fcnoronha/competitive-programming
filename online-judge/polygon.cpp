//onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=575

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
    while (cin >> n && n) {
        pll pt[n], q;
        fr(i, n) cin >> pt[i].f >> pt[i].s;
        cin >> q.f >> q.s;

        int cnt = 0;
        for (int i = 0; i < n; i++) {

            if (min(pt[i].f, pt[(i+1)%n].f) <= q.f) continue;
            
            int mxy = max(pt[i].s, pt[(i+1)%n].s), mny = min(pt[i].s, pt[(i+1)%n].s);
            cnt += (q.s <= mxy && q.s >= mny);
        }
        if (cnt%2) p('T');
        else p('F');
    }
}
