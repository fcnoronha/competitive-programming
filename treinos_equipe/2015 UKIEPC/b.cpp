// codeforces.com/gym/100800

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

const ld pi = acos(-1.0l);

int main(){

	int n;
	ld g;
	cin >> n >> g;

	ld ans[n+2];

	pii a[n+2];
	fr(i, n)
		cin >> a[i].f >> a[i].s;

	fr(i, n){

		ld ret;

		for (int j = i; j < n; j++){

			if (j == i){
				ret = a[j].f * cos((a[j].s*pi)/180);
			}

			else {
				ret = ret + a[j].f * cos((a[j].s*pi)/180);
			}
		}

		ans[i] = sqrt(ret * 2 * g);
	}

	fr(i, n)
		printf("%.10Lf\n", ans[i]);

}
