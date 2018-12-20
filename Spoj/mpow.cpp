// https://www.spoj.com/problems/MPOW/

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

const ll mod = 1000000007; 

typedef vector< vector<ll> > matrix;

ll n;

matrix operator*(matrix& a, matrix& b){

	matrix aux; aux.resize(n);
	
	for (int i = 0; i < n; i++)
		aux[i].resize(n);
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			aux[i][j] = 0ll;
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
		fr(j, x) v[i][j] = 0ll;
		v[i][i] = 1ll;
	}
	return v;
}

void exp(matrix& a, ll x){
	matrix ans = id(n);
	while (x > 0){
		if(x%2 == 1)
			ans=ans*a;
		a=a*a;
		x=x/2;
	}

	a = ans;
}

int main(){
	int t;
	cin >> t;
	while (t--){

		ll e;
		cin >> n >> e;

		matrix v;

		fr(i, n){
			vector<ll> aux;
			fr(j,n){
				ll x;
				cin >> x;
				aux.pb(x);
			}
			v.pb(aux);
		}

		exp(v, e);

		for (auto u : v){
			for (auto h : u)
				cout << h << " ";
			cout << endl;
		}
	}
}
