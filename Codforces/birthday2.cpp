// codeforces.com/contest/1131/problem/C

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

	vi a;
	int x;
	fr(i, n) cin >> x, a.pb(x);

	sort(all(a));

	vi a1, a2;
	fr(i, n){
		if (i%2 == 0) a1.pb(a[i]);
		else a2.pb(a[i]);
	}

	fr(i, a1.size()) cout << a1[i] << " ";
	reverse(all(a2));
	fr(i, a2.size()) cout << a2[i] << " \n"[i == a2.size()-1];
}
