//codeforces.com/contest/1114/problem/A

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

	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;

	int aux = min(x, a);
	x -= aux;
	a -= aux;

	aux = min(y, a);
	y -= aux;
	a -= aux;

	aux = min(y, b);
	y -= aux;
	b -= aux;

	aux = a+b+c;
	if (aux >= z) z = 0;

	if (x+y+z == 0) p(YES);
	else p(NO);		
}
