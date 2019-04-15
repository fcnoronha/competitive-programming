// codeforces.com/contest/1144/problem/C

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
	int freq[200009];
	ms(freq, 0);

	bool vaida = true;
	fr(i, n){
		cin >> a[i];
		freq[a[i]]++;

		if (freq[a[i]] > 2)
			vaida = false;
	}

	if (!vaida){
		p(NO);
		return 0;
	}

	sort(a, a+n);
	vi v1, v2;

	fr(i, n){

		if (i > 0 && a[i] == a[i-1]){
			v2.pb(a[i]);
			continue;
		}

		v1.pb(a[i]);
	}
	p(YES);

	reverse(all(v2));
	cout << v1.size() << endl;
	pv(v1);
	if (v1.size() == 0) cout << endl;
	cout << v2.size() << endl;
	pv(v2);
	if (v2.size() == 0) cout << endl;
}
