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

#define maxn 1123456
bool lzy[maxn];
pll seg[maxn];
ll mxy, h;

void apply(ll p) {
    swap(seg[p].f, seg[p].s);
    if (p < mxy) lzy[p] = !lzy[p];
}

void build(ll p) {
    while (p > 1) {
        p >>= 1;
        seg[p].f = seg[p<<1].f + seg[p<<1|1].f;
        seg[p].s = seg[p<<1].s + seg[p<<1|1].s;
        if (lzy[p]) swap(seg[p].f, seg[p].s);
    }
}

void push(ll p) {
    for (ll s = h; s > 0; s--) {
        ll i = p>>s;
        if (lzy[i]) {
            apply(i<<1);
            apply(i<<1|1);
            lzy[i] = 0;
        }
    }
}

void update(ll l, ll r) {
    l += mxy, r += mxy;
    ll l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++);
        if (r&1) apply(--r);
    }
    build(l0);
    build(r0-1);
} 

ll query(ll l, ll r) {
    l += mxy, r += mxy;
    push(l);
    push(r-1);
    ll ans = 0;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans += seg[l++].f;
        if (r&1) ans += seg[--r].f;
    }
    return ans;
}

int main() {
    fastio;

    ll n;
    cin >> n;
    
    multiset< pair<pll, pll> > ev;
    set<ll> ycord;
    fr(i, n) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // {x1,y1} lower left
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        ev.insert( {{x1, 1}, {y1, y2}} ); // enter
        ev.insert( {{x2, 0}, {y1, y2}} ); // exit
        ycord.insert(y1);
        ycord.insert(y2);
    }

    int yclk = 0;
    map<ll, ll> mp, rmp;
    for (auto y: ycord) {
        mp[y] = ll(yclk);
        rmp[ll(yclk)] = y;
        yclk++; 
    }
    mxy = ll(yclk);
    h = 32ll - ll(__builtin_clz(yclk));

    fr(i, mxy) 
        seg[i+mxy].s = rmp[i+1] - rmp[i];
    for (ll i = mxy-1; i > 0; i--) 
        seg[i].s = seg[i<<1].s + seg[i<<1|1].s; 

    ll lst = -1, ans = 0ll;
    for (auto aux: ev) {

        ll curx = aux.f.f;
        ll y1 = aux.s.f, y2 = aux.s.s;

        if (lst != -1) {
            ll delta = curx-lst;
            ans += delta * query(0, mxy);
        }
        lst = curx;
        update(mp[y1], mp[y2]);
    }

    cout << ans << endl;
}

/*
2
1 1 2 2
1 1 2 2
*/