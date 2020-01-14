//codeforces.com/contest/1251/problem/D

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

#define maxn 200009

pll lmt[maxn];
ll n, s;

int check(ll val) {

    bool used[n];
    ms(used, 0);

    ll aux = s-val;

    int less = 0, more = 0;
    fr(i, n) {

        auto a = lmt[i];

        if (a.f > val) {
            more++;
            aux -= a.f;
            used[i] = 1;
            continue;
        }

        if (a.s < val) {
            less++;
            aux -= a.f;
            used[i] = 1;
            continue;
        }
    }

    if (less > n/2) return -1;
    if (more > n/2) return 1;
    if (aux < 0) return -1;

    fr(i, n) {
        if (used[i]) continue;
        if (less == n/2) continue;
        
        aux -= lmt[i].f;
        used[i] = 1;
        less++;
    }

    fr(i, n) {
        if (used[i]) continue;
        if (more == n/2) continue;
        
        aux -= val;
        used[i] = 1;
        more++;
    }

    if (aux < 0) return -1;
    return 1;
}

int main(){
    fastio;

    int t;
    cin >> t;

    while (t--) {

        cin >> n >> s;

        fr(i, n) cin >> lmt[i].f >> lmt[i].s;

        sort(lmt, lmt+n);

        ll l = LINF, r = -1;
        fr(i, n) {
            l = min(l, lmt[i].f);
            r = max(r, lmt[i].s);
        }

        ll m;
        fr(i, 35) {
            
            m = (r+l)/2;

            if (check(m) > 0) l = m+1;
            else r = m-1;
        }

        p(m); // tem que acabar
    }
}
