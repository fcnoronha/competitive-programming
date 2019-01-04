// http://www.codcad.com/problem/55

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
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
	
	int n, m;
	cin >> n;

	vector<pii> v(100009, {-1,-1});

	fr(i, n){
		int x;
		cin >> x;

		v[x] = {i, x};
	} 

	cin >> m;
	fr(i, m){
		int x;
		cin >> x;
		v[x] = {-1, x};
	}

	sort(v.begin(), v.end());

	for (auto u : v) if (u.f != -1) cout << u.s << " \n"[u.s == (*(v.end()-1)).s];
}
