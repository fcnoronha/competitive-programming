// codeforces.com/contest/1108/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

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

int main(){
	fastio

	int n;
	cin >> n;

	vector<pii> v(n, {0, 1});

	fr(i, n) cin >> v[i].f;

	sort(all(v));
		
	int ansx = v[n-1].f;

	fr(i, n) if (ansx%v[i].f == 0 && !(i > 0 && v[i].f == v[i-1].f)) v[i].s = 0;

	int ansy;
	fr(i, n) if (v[i].s) ansy = v[i].f;

	cout << ansx << " " << ansy << endl;
}
