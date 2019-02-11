//codeforces.com/contest/1110/problem/C

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

bool isf[(1<<25)];
int maxd[(1<<25)];

int main(){
	fastio
	
	int aux = 0;
	frr(i, 25){
		aux = (1<<i)-1;
		isf[aux] = 1;
	}

	fr(i, (1<<25)){

		if (isf[i]){

			for(int d = 1; d < i; d++)
				if (i%d == 0) maxd[i] = d;
		}
	}

	int q;
	cin >> q;

	while (q--){

		int a;
		cin >> a;

		int x = 0;
		while ((1<<x) <= a) x++;
		x = ((1<<x));

		if (x == a+1) cout << maxd[a] << endl;
		else cout << x-1 << endl;
	}	
}
