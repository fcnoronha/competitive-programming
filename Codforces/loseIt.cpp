//codeforces.com/contest/1176/problem/C

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

int heh[50], aux[6];

int main(){
	fastio

	heh[4] = 0;
	heh[8] = 1;
	heh[15] = 2;
	heh[16] = 3;
	heh[23] = 4;
	heh[42] = 5;

	int n;
	cin >> n;

	int a[n];
	fr(i, n)
		cin >> a[i], a[i] = heh[ a[i] ];

	fr(i, n) {

		if (a[i] == 0) {
			aux[0]++;
			continue;
		}

		if (aux[ a[i]-1 ] > 0){
			aux[ a[i]-1 ]--;
			aux[ a[i] ]++;
		}
	}

	cout << n - 6*aux[5] << endl;
}
