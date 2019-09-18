#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define pb push_back
#define f first
#define s second

#define dbg(x) cout << #x << "=" << x << endl;
#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;

const ll INF =  0x3f3f3f3f;

#define maxn 2000

// M - x   |    N - Y

ll m, n, k;
ll id[maxn], sz[maxn];
pair< pii, pii > lmt[maxn]; // {{lmt no x}, {lmt no y}}
pii pos[maxn];
ll raio[maxn];

void opa(ll i, ll j) {

	pii x1 = lmt[i].f;
	pii x2 = lmt[j].f;

	ll a = min({x1.f, x1.s, x2.f, x2.s});
	ll b = max({x1.f, x1.s, x2.f, x2.s});

	pii y1 = lmt[i].s;
	pii y2 = lmt[j].s;

	ll c = min({y1.f, y1.s, y2.f, y2.s});
	ll d = max({y1.f, y1.s, y2.f, y2.s});

	lmt[i] = lmt[j] = {{a,b},{c,d}};
}

ll find(ll p) {
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void uni(ll p, ll q) {

	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p,q);

	opa(p, q);

	id[p] = q;
	sz[q] += sz[p];
}

int main() {
	
	cin >> m >> n >> k;

	fr(i, k+3) id[i] = i, sz[i] = 1;

	fr(i, k) {

		ll x, y, s;
		cin >> x >> y >> s;

		pos[i] = {x,y};
		raio[i] = s;
		lmt[i] = {{x-s,x+s}, {y-s,y+s}};
	}

	fr(i, k)  
		if (lmt[i].f.s >= m && lmt[i].s.s >= n) {
			cout << "N\n";
			return 0;
		}


	fr(i, k) 
		if (lmt[i].f.f <= 0 && lmt[i].s.f <= 0) {
			cout << "N\n";
			return 0;
		}
	
	fr(i, k) {
		fr(j, k) {
			if (i == j) continue;

			ll x1 = pos[i].f, y1 = pos[i].s;
			ll x2 = pos[j].f, y2 = pos[j].s;
			ll s1 = raio[i], s2 = raio[j];

			if ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= (s1+s2)*(s1+s2))	
				uni(i, j);
		}
	}

	fr(i, k) 
		if (lmt[find(i)].f.s >= m && lmt[find(i)].s.s >= n) {
			cout << "N\n";
			return 0;
		}

	fr(i, k) 
		if (lmt[i].f.f <= 0 && lmt[i].s.f <= 0) {
			cout << "N\n";
			return 0;
		}
	

	fr(i, k) {

		ll oi = find(i);
		pii x = lmt[oi].f;
		pii y = lmt[oi].s;

		if ((x.f <= 0 && x.s >= m) || (y.f <= 0 && y.s >= n)) {
			cout << "N\n";
			return 0;
		} 
	}

	cout << "S\n";
}