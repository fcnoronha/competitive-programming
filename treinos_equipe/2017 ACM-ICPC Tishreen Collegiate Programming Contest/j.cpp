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

ll id[1009], sz[1009], ri[1009];
pll max_w[1009], pos[1009];

pll calc_max(pll a, pll b) {

    ll x = min( min(a.f, a.s), min(b.f, b.s) );
    ll y = max( max(a.f, a.s), max(b.f, b.s) );

    return {x, y};
}

ll find(ll p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void uni(ll p, ll q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

    max_w[q] = calc_max(max_w[q], max_w[p]);
    max_w[p] = calc_max(max_w[q], max_w[p]);

	id[p] = q;
	sz[q] += sz[p];
}

int main(){
    fastio

    int t;
    cin >> t;

    while (t--) {
        ll n, l, w;
        cin >> n >> w >> l;

        fr(i, n) id[i] = i, sz[i] = 1;

        ll x, y, r;
        fr(i, n) {
            cin >> x >> y >> r;

            pos[i] = {x, y};
            ri[i] = r;
            max_w[i] = {x-r, x+r};
        }

        fr(i, n) {
            fr(j, n) {

                if (i == j) continue;

                ll dist = (pos[i].f-pos[j].f)*(pos[i].f-pos[j].f) +
                          (pos[i].s-pos[j].s)*(pos[i].s-pos[j].s);

                ll rs = ri[i] + ri[j];
                rs *= rs;

                if (dist > rs) continue;

                uni(i, j);
            }
        }

        set<int> aux;
        fr(i, n)
            aux.insert(find(i));

        int ans = 0;
        for (auto u : aux)
            ans += (max_w[u].f <= 0 && max_w[u].s >= w);

        p(ans);
    }
}
