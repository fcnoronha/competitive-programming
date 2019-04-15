// codeforces.com/contest/1143/problem/C

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

	int r;
	vi adj[n+3];
	bool c[n+3];
	ms(c, 0);

	frr(i, n){
		int a, b;
		cin >> a >> b;

		if (a != -1)
			adj[a].pb(i);
		else
			r = i;

		c[i] = b;
	}

	vi ans;
	frr(i, n){

		bool aux = c[i];
		for (auto u : adj[i])
			aux &= c[u];

		if (aux)
			ans.pb(i);
	}

	sort(all(ans));
	if (ans.size() > 0){
		pv(ans);
	}
	else
		p(-1);
}
