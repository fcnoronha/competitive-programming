//codeforces.com/contest/1152/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int p1, p2, i1, i2, aux;
int main(){
	fastio

	int n, m;
	cin >> n >> m;

	fr(i, n) {
		cin >> aux;
		p1 += (aux%2 == 0);
		i1 += (aux%2 == 1);
	}

	fr(i, m) {
		cin >> aux;
		p2 += (aux%2 == 0);
		i2 += (aux%2 == 1);
	}

	p(min(p1, i2) + min(p2, i1));
}
