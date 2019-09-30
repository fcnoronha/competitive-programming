// poj.org/problem?id=1758

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

// Orientaçao de 3 pintos:
// 0 --> p, q and r are colinear
// >0 --> Clockwise
// <0 --> Counterclockwise
int ori(pii p1, pii p2, pii p3){

    int val = (p2.s - p1.s) * (p3.f - p2.f) -
              (p2.f - p1.f) * (p3.s - p2.s);

 	return val;
}

// Distancia euclidiana:
ld eucDist(pii p1, pii p2) {
	return sqrt((1.0l)*(p1.f - p2.f)*(p1.f - p2.f) +
				(1.0l)*(p1.s - p2.s)*(p1.s - p2.s));
}

int main(){
	fastio

	int n, m;
	cin >> n >> m;

	pii gt[n+2];
	fr(i, n)
		cin >> gt[i].f >> gt[i].s;

	pii hm[m+2];
	fr(i, m)
		cin >> hm[i].f >> hm[i].s;

	ld w[n][n];
	fr(i, n) fr(j, n) w[i][j] = DBL_MAX;

	// Each possible combination
	fr(a, n) {
		fr(b, n) {

			if (a == b)
				continue;

			int check = 0;

			// all monuments
			fr(p, m) {

				int cmp = ori(gt[a], gt[b], hm[p]);

				if (cmp > 0) check--;
				else if (cmp < 0) check++;
			}

			if (check == m)
				w[a][b] = eucDist(gt[a], gt[b]);

			else if (check == -m)
				w[b][a] = eucDist(gt[a], gt[b]);

		}
	}

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);

	ld ans = DBL_MAX;
	fr(r, n)
	 	fr(a, n)
			fr(b, n)
				if (ori(gt[r], gt[a], gt[b]) != 0)
					ans = min(ans, w[r][a] + w[a][b] + w[b][r]);

	cout << setprecision(2) << fixed << ans << endl;
}
