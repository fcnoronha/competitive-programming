#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mod = 1e9+7; // To be defined

// Calculates factorial of a number
ll fat(ll x){
	if (x == 0) return 1;
	return x*fat(x-1)%mod;
}

// Calculates exponenciation in a fast way
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

// For you to devide a number that is in a modulo(%)
ll invmod(ll x){
	return fastexp(x, mod-2);
}