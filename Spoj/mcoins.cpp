// www.spoj.com/problems/MCOINS/

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

bool isw[1000009];

int main(){
	fastio

	int k,l,m;
	cin >> k >> l >> m;

	fr(i, 1000009){
		if (isw[i]) continue;
		isw[i+1] = isw[i+k] = isw[i+l] = 1;
	}

	fr(i, m){
		int aux;
		cin >> aux;

		if (isw[aux]) cout << "A";
		else cout << "B";
	}

	cout << endl;
}
