//codeforces.com/contest/1130/problem/A

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

	int n, ps = 0, ng = 0, x;

	cin >> n;

	fr(i, n){
		cin >> x;

		if (x > 0) ps++;
		else if (x < 0) ng++;
	}

	x = ceil(n/2.0);
	if (ps < x && ng < x){
		p(0);
		return 0;
	}

	if (ps >= x){
		p(1);
		return 0;
	}

	p(-1);
}
