/*
	Modified code for matrix exponentiation to account for large numbers,
	with better tools for handling modular arithmetic.
	Original can be found here: https://github.com/splucs/Competitive-Programming/blob/master/Macac%C3%A1rio/Math/matrixexp.cpp
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<vector<ll>> matrix;
const ll MOD = 1000000007;

matrix operator *(matrix a, matrix b) {
	ll n = (int)a.size();
	ll m = (int)b.size();
	ll p = (int)b[0].size();
	matrix c(n, vector<ll>(p));
	ll col[m];
	for (ll j = 0; j < p; j++) {
		for (int k = 0; k < m; k++)
			col[k] = b[k][j];
		for (int i = 0; i < n; i++) {
			ll s = 0;
			for (int k = 0; k < m; k++){
				ll aux = ((a[i][k]%MOD) * (col[k]%MOD))%MOD;
				s = (s%MOD + aux)%MOD;

			}
			c[i][j] = s%MOD;
		}
	}
	return c;
}

matrix id(ll n) {
	matrix c(n, vector<ll>(n));
	for(ll i = 0; i < n; i++) c[i][i] = 1;
	return c;
}

matrix matrixExp(matrix a, ll n) {
	if (n == 0) return id(a.size());
	matrix c = matrixExp(a, n/2);
	c = c*c;
	if (n%2 != 0) c = c*a;
	return c;
}


int main() {
    ll t; scanf("%lld", &t);
    while(t--){
        ll m, n;
        scanf("%lld%lld", &m, &n);
        ll cnt = 1;
        ll vaca = n;
        while(vaca != 0){
            vaca /= 10;
            cnt *= 10;
        }

        m--;

        //if(m == 0) printf("%lld\n", n);

        matrix aux = matrixExp({{cnt, 1}, {0, 1}}, m);

        aux = aux*matrix({{n}, {n}});

        printf("%lld\n", aux[0][0]%MOD);


    }
}
