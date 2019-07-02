// codeforces.com/contest/1180/problem/B

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

	int n;
	cin >> n;

	ll a[n+10];
	fr(i, n)
		cin >> a[i];

	int n_zero = 0, n_pos = 0, n_neg = 0;
	fr(i, n){
		n_zero += (a[i] == 0ll);
		n_pos += (a[i] > 0);
		n_neg += (a[i] < 0);

	}

	ll mn = LLONG_MAX;
	fr(i, n) if (a[i] >= 0) a[i] = -abs(a[i])-1;
	fr(i, n) mn = min(mn, a[i]);

	if (n%2 == 0){
		fr(i, n)
			cout << a[i] << " ";
		cout << endl;
		return 0;
	}

	fr(i, n) {
		if (a[i] == mn) a[i] = -a[i]-1, mn = LLONG_MAX;
		cout << a[i] << " ";
	}
	cout << endl;

}
