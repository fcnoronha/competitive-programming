// https://www.urionlinejudge.com.br/judge/pt/problems/view/1474

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll mod = 1000000;

typedef vector< vector<ll> > matrix;

int n = 2;

matrix operator*(matrix& a, matrix& b){

	matrix aux; aux.resize(n);
	
	for (int i = 0; i < n; i++)
		aux[i].resize(n);
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			aux[i][j]=0ll;
			for (int k = 0; k < n; k++){
				aux[i][j] += a[i][k] * b[k][j];
				aux[i][j] = aux[i][j] % mod;
			}
		}
	}
	return aux;
}

matrix id(int x){
	matrix v;
	v.resize(x);
	for (int i = 0; i < x; i++){
		v[i].resize(x);
		v[i][i] = 1ll;
	}
	return v;
}

void exp(matrix& a, ll x){
	matrix ans = id(a.size());
	while (x > 0){
		if(x%2 == 1)
			ans=ans*a;
		a=a*a;
		x=x/2;
	}

	a = ans;
}

ll oi(ll n, ll k, ll l){
	if (n == 0) return 1;
	if (n == 1) return k;
	return k*oi(n-1, k, l) + k*oi(n-2, k, l);
} 

int main(){

	/*
		
		|	F(n)	|	=	|0	1|n *	|F(0)|
		|	F(n+1)	| 		|l	k|		|F(1)|

	*/

	ll e, k, l;
	while (cin >> e && e != EOF){
		cin >> k >> l;

		k %= mod; l %= mod;

		e /= 5;
		matrix v = {{0,1}, {l,k}};
		exp(v, e);

		ll ans = (v[0][0] + (k*v[0][1]))%mod;
		//ans = v[1][1];

		//ll t = oi(e, k, l);
		//if (t%mod == ans%mod) cout << (t%mod) << " sim" << endl;

		vi porracaralho;
		fr(i, 6){
			porracaralho.pb(ans%10);
			ans /= 10;
		}

		reverse(porracaralho.begin(), porracaralho.end());
		for (auto u : porracaralho)
			cout << u;

		cout << endl;
	}
}
