#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

#define maxn 112345

typedef struct{
    int f, s, i;
} qry;

qry q[maxn];
ll n, m, k, bsz;
ll a[maxn];
ll vans[maxn];
ll cnt[9000009];
ll ans;

bool comp(qry a, qry b) {
    if (a.f/bsz != b.f/bsz) return a.f/bsz < b.f/bsz;
    return a.s < b.s;
}

void add(ll v) {
    ans += cnt[v^k];
    cnt[v]++;
}

void remove(ll v) {
    cnt[v]--;
    ans -= cnt[v^k];
}

void mos(ll n, ll m) {

    bsz = static_cast<int>(floor(sqrt(n)));

    sort(q, q+m, comp);

    ll cr = 0, cl = 0;

    fr(i, m) {

        ll l = q[i].f-1;
        ll r = q[i].s;

        while (cl < l) remove(a[cl++]);
        while (cl > l) add(a[--cl]);

        while (cr < r) add(a[++cr]); 
        while (cr > r) remove(a[cr--]);			

        vans[q[i].i] = ans;
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio
    
    cin >> n >> m >> k;
    cnt[0]++;
    frr(i, n) cin >> a[i], a[i] ^= a[i-1];

    fr(i, m) cin >> q[i].f >> q[i].s, q[i].i = i;

    mos(n, m);

    fr(i, m) cout << vans[i] << endl;
}
