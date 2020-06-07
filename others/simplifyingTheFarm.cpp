//vjudge.net/contest/376169#problem/D

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

#define maxn 41234
const ll mod = 1000000007;

map<pll, ll> cst, seen, cnt;

// UF

ll id[maxn], sz[maxn];

int find(int p) {
    if (id[p] == p) return p;
    return id[p] = find(id[p]);
}

void uni(int p, int q) {
    p = find(p);
    q = find(q);
    if (p == q) return;
    if (sz[p] > sz[q]) swap(p, q);
    id[p] = q;
    sz[q] += sz[p];
}

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    frr(i, n) id[i] = i, sz[i] = 1;

    fr(i, m) {
        ll a, b, lf;
        cin >> a >> b >> lf;

        if (cst[{a,b}] > lf || cst[{a,b}] == 0) {
            cst[{a,b}] = cst[{b,a}] = lf;
            cnt[{a,b}] = cnt[{b,a}] = 1;
        }
        else if (cst[{a,b}] == lf) {
            cnt[{a,b}]++;
            cnt[{b,a}]++;
        }
    }

    map<ll, vector<pll>> mp;
    for (auto x: cst) {
        if (seen[x.f]) continue;
        mp[x.s].pb(x.f);
        seen[x.f] = seen[{x.f.s, x.f.f}] = 1;
    }

    ll ans = 1, tcost = 0ll;
    for (auto x: mp) {

        set<pll> ste, stc;
        ll avlb_e = 0ll;
        for (auto edg: x.s) {
            int u = edg.f, v = edg.s;
            if (find(u) == find(v)) continue;
            avlb_e += cnt[edg];
            u = find(u); v = find(v);
            stc.insert( {min(u, v), max(u, v)} );
        }

        ll avlb_c = stc.size();
        ll merges = 0ll;
        for (auto edg: stc) {
            int u = edg.f, v = edg.s;
            if (find(u) == find(v)) continue;
            uni(u, v);
            merges++;
            tcost += x.f;
        }

        if (avlb_e == 3 && merges == 1) ans = (ans*3ll)%mod;
        else if (avlb_e == 3 && avlb_c == 3 && merges == 2) ans = (ans*3)%mod;
        else if (avlb_e == 3 && avlb_c == 2 && merges == 2) ans = (ans*2)%mod;
        else if (avlb_e == 2 && merges == 1) ans = (ans*2)%mod;
    }

    cout << tcost << " " << ans << endl;
}
