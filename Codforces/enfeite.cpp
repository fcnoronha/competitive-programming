// http://codeforces.com/group/btcK4I5D5f/contest/225478/problem/K

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll mod = 1e9+7;

int n, x;
string smp, giv;
ll pdm[104];

ll fat(ll x){
	if (x == 0) return 1;
	return x*fat(x-1)%mod;
}

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

ll pd(ll x){
	if (x < 0) return 0;
	if (x == 0) return 1;

	if (pdm[x] != -1) return pdm[x];

	ll ans = 0;
	for (int i = 1; i <= x; i++){
		ll c = fat(x); 
		ll a = fat(i);
		a = invmod(a);
		ll b = fat(x-i);
		b = invmod(b);
		c = (c*a)%mod;
		c = (c*b)%mod;
		ans += c * pd(x-i);
		ans %= mod;
	}
	pdm[x] = ans;
	return ans;
}

int main(){
	cin >> n >> giv >> smp;
	for (int i = 0; i < n; i++){
		if (giv[i] == 'o' && smp[i] == '.') x++;
	}

	fill(pdm, pdm+103, -1);	

	if (x == 0) cout << "0" << endl;
	else cout << pd(x) << endl;
}