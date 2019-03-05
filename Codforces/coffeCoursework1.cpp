//codeforces.com/contest/1118/problem/D1

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

	int n, m;
	cin >> n >> m;

	int a[n], mx = 0;
	fr(i, n) cin >> a[i], mx += a[i];

	int grg = mx - m;

	if (grg < 0){
		p(-1);
		return 0;
	}

	sort(a, a+n);
	reverse(a, a+n);

	frr(i, n){

		int ans = 0;
		int cnt = -1;

		for (int j = 0; j < n; j++){
			cnt += (j%i == 0);
			if (cnt >= a[j]) break;

			ans += a[j] - cnt;
		}

		if (ans >= m){
			cout << i << endl;
			return 0;
		}
	}
}
