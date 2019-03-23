// codeforces.com/contest/1132/problem/C

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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

int main(){
	fastio

	int n, q;
	cin >> n >> q;
	pii v[q];

	fr(i, q)
		cin >> v[i].f >> v[i].s;

	int aux[n+3];
	ms(aux, 0);

	fr(i, q){
		aux[v[i].f] += 1;
		aux[v[i].s + 1] -= 1;
	}

	int ans = 0;
	fr(i, q){

		int d[n+3];
		ms(d, 0);
		d[v[i].f] -= 1;
		d[v[i].s + 1] += 1;

		frr(i, n+2)
		 	d[i] += aux[i] + d[i-1];

		int cnt = 0;
		fr(i, n+3)
			cnt += (d[i] > 0);

		fr(i, n+3)
			if (d[i] > 1) d[i] = 0;

		frr(i, n+2)
			d[i] += d[i-1];

		int mn = INT_MAX;
		fr(j, q){

			if (i == j) continue;

			mn = min(mn, d[v[j].s] - d[v[j].f-1]);
		}

		ans = max(ans, cnt-mn);
	}

	cout << ans << endl;
}
