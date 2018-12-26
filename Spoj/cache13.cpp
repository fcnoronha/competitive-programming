// http://br.spoj.com/problems/CACHE13/
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

int t = 2;

matrix operator*(matrix& a, matrix& b){

	matrix aux; aux.resize(t);
	
	for (int i = 0; i < t; i++)
		aux[i].resize(t);
	
	for (int i = 0; i < t; i++){
		for (int j = 0; j < t; j++){
			aux[i][j]=0ll;
			for (int k = 0; k < t; k++){
				aux[i][j] += (a[i][k] * b[k][j])%mod;
				aux[i][j] += mod;
				aux[i][j] %= mod;
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
	ll n, ans;
	cin >> n;

	matrix v = {{5, -2}, {1, 0}};
	exp(v, n-1);

	ans = ((54*v[1][0] + 12*v[1][1]))%mod;

	cout << ans << endl;
}
