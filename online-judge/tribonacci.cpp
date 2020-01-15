// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3914

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

const ll mod = 1000000009;

typedef vector< vector<ll> > matrix;

ll n = 3;

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

int main(){
	ll n;
	while (cin >> n && n != 0){
		if (n <= 3)
			cout << n-1 << endl;
		else {

			matrix v = {{1,1,1}, {1,0,0}, {0,1,0}};
			exp(v, n-3);
			ll ans = 2*(v[0][0])%mod;
			ans += (v[0][1]);
			ans %= mod;
			cout << ans << endl;
		}
	}
}
