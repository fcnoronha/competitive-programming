// codeforces.com/contest/1131/problem/B

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

	ll mn = 0, a, b, n, ans = 1;
	cin >> n;

	pll ant = {0, 0}, x;
	fr(i, n+1){
		if (i < n) cin >> x.f >> x.s;
		else x = ant;

		ans += max(0ll, min(x.s, x.f) - max(ant.f, ant.s) + (ant.f != ant.s));
		ant = x;
	}

	cout << ans << endl;
}
