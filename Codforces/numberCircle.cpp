//codeforces.com/contest/1189/problem/B

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

	int a[n];
	fr(i, n) cin >> a[i];

	sort(a, a+n);

	if (a[0] + a[n-2] <= a[n-1]){

		int idx = n-2;
		swap(a[n-2], a[n-1]);

		while (idx > 1 && (a[idx-1]+a[idx+1] <= a[idx])) {
			swap(a[idx-1], a[idx]);
			idx--;
		}
	}

	fr(i, n-2) {

		if (a[i] + a[i+2] <= a[i+1]) {
			p(NO);
			return 0;
		}
	}

	if (a[0] + a[n-2] <= a[n-1] || a[1] + a[n-1] <= a[0]){
		p(NO);
		return 0;
	}

	p(YES);
	fr(i, n) cout << a[i] << " ";
	cout << endl;
}
