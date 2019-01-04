// codeforces.com/contest/1097/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
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

const ll mod = 1e9+7;

ll fastexp(ll base, ll exp){
	ll ans = 1;
	while(exp){
		if(exp%2) {
			ans *= base;
			ans %= mod;
		}
		base *= base;
		base %= mod;
		exp /= 2;
	}
	return ans;
}

ll invmod(ll x){
	return fastexp(x, mod-2);
}

typedef vector< vector<long double> > matrix;

ll t = 4;

matrix operator*(matrix& a, matrix& b){

	int a1=t; int a2=t;
	int b1=t; int b2=t;

	matrix aux; aux.resize(t);
	
	for (int i = 0; i < t; i++)
		aux[i].resize(b2);
	
	for (int i = 0; i < a1; i++){
		for (int j = 0; j < b2; j++){
			aux[i][j]=0ll;
			for (int k = 0; k < a2; k++)
				aux[i][j] = (aux[i][j] + (a[i][k] * b[k][j]));
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

vi divs;

int geraDiv(ll n){

	for (int i = 1; i <= n; i++)
		if (n%i == 0) divs.pb(i), dbg(i);
	divs.pb(n);
	return divs.size();
}

int main(){
	fastio

	ll n , k;
	cin >> n >> k;

	int nDiv = geraDiv(n);

	matrix v;
	fr(i, nDiv){
		vector<long double> aux;
		fr(j , nDiv) aux.pb(0.0);
		v.pb(aux);
	}

	// Tenho que ver como que gero todos os divisores pra n == 10^15

	dbg(nDiv);

	// matrix v = {{1,1/2.0,1/2.0,(1/4.0)}, 
	// {0,1/2.0,0,1/4.0}, {0,0,1/2.0,1/4.0}, {0,0,0,1/4.0}};

	exp(v, k);

	fr(i,4){
		fr(j, 4) cout << v[i][j] << " ";
		cout << endl;
	}

	double ans = 0.0;
	ans += v[0][3];
	ans += 2.0*v[1][3];
	ans += 3.0*v[2][3];
	ans += 6.0*v[3][3];
	ans *= (double)pow(nDiv,k);


	// A ideia era usar fastExp pra achar a prob de cada divisor e depois
	// simplimente calcular a experanca. Dai é so multiplicar pelo numero
	// de divisores elevado a K, e dpois so fazer igual aq em baixo

	cout << ((int)ans * invmod(pow(nDiv, k)))%mod << endl;
}
