//codeforces.com/contest/1162/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio

	int n, m;
	cin >> n >> m;

	int a[n][m], b[n][m];
	fr(i, n) fr(j, m) cin >> a[i][j];
	fr(i, n) fr(j, m) cin >> b[i][j];

	fr(i, n) fr(j, m) if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);

	fr(i, n) {
		fr(j, m) {

			if (j == m-1 && i == n-1) continue;

			if (j == m-1) {
				if (a[i][j] >= a[i+1][j] || b[i][j] >= b[i+1][j]) {
					p("Impossible");
					return 0;
				}
			}

			else if (i == n-1) {
				if (a[i][j] >= a[i][j+1] || b[i][j] >= b[i][j+1]) {
					p("Impossible");
					return 0;
				}
			}

			else if (a[i][j] >= a[i+1][j] || b[i][j] >= b[i+1][j] ||
				a[i][j] >= a[i][j+1] || b[i][j] >= b[i][j+1]) {

					p("Impossible");
					return 0;
				}
		}
	}

	p("Possible");
}
