// vjudge.net/contest/301866#problem/A

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

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

const double PI = acos(-1);

int main() {

	int n;
	double r;

	cin >> n >> r;

	pdd pos[n];

	fr(i, n)
		cin >> pos[i].f >> pos[i].s;

	double ans = 2.0 * PI * r;

	cout << setprecision(2) << fixed;
	if (n == 1) {
		cout << ans << endl;
		return 0;
	}

	fr(i, n-1) {

		double dist = (pos[i].f - pos[i+1].f) * (pos[i].f - pos[i+1].f);
		dist += (pos[i].s - pos[i+1].s) * (pos[i].s - pos[i+1].s);

		ans += sqrt(dist);
	}

	double dist = (pos[n-1].f - pos[0].f) * (pos[n-1].f - pos[0].f);
	dist += (pos[n-1].s - pos[0].s) * (pos[n-1].s - pos[0].s);
	ans += sqrt(dist);

	cout << ans << endl;
}
