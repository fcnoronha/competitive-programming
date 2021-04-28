#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
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

#define maxn 312345

ll v[maxn];
pll mp[maxn], nv[maxn], ac_h[maxn];
ll n, cnt1 = 0;

bool check(int i, int j, int mx) {

    if (i <= 0) return false;

    pll oi = {nv[i-1].f ^ nv[j].f, nv[i-1].s ^ nv[j].s};

    return oi == ac_h[mx];
}

ll go() {

    nv[0] = {0,0};
    frr(j, n) nv[j] = {nv[j-1].f ^ mp[v[j]].f, nv[j-1].s ^ mp[v[j]].s};

    ll mx = 0, ans = 0;
    frr(j, n) {

        if (v[j] == 1) {
            cnt1++;
            mx = 0;
            continue;
        }

        mx = max(mx, v[j]);
        int i = j-mx+1;

        ans += check(i, j, mx);
    }

    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    srand(time(NULL));

    cin >> n;

    frr(i, n) {
        mp[i].f = rand() % LLONG_MAX;
        mp[i].s = rand() % LLONG_MAX;
        ac_h[i] = {ac_h[i-1].f ^ mp[i].f, ac_h[i-1].s ^ mp[i].s};
    }
    
    frr(i, n) {
        cin >> v[i];
    }

    ll ans = go();
    reverse(v+1, v+n+1);
    reverse(nv+1, nv+n+1); 
    ans += go();

    p(ans+cnt1/2);
}
