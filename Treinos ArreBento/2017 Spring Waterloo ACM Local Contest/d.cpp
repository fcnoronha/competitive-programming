//codeforces.com/gym/101431/problem/D

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

	int n, x;
	cin >> n >> x;

	if (x >= n){
		p(-1);
		return 0;
	}

	if (x == 1){
		frr(i, n){
			int aux = i+1;
			if (aux == n+1)
				aux = 1;
			cout << i << " " << aux << endl;
		}
		return 0;
	}
	
	vi vp[n+10];
	vi vs[n+10];
	int ind = 0, aux = 1;
	frr(i, n*x){
		
		//dbg(aux);
		vp[ind].pb(i);
		vs[(aux+ind)%n].pb(i);
		ind = (ind+1)%n;

		aux += (i%n == 0 && i < (n*x));
	}

	fr(i, n){
		fr(j, x) cout << vp[i][j] << " ";
		fr(j, x) cout << vs[i][j] << " \n"[j == x-1];
	}
}
