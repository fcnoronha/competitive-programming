#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mod = 1e9+7; // To be defined

// Calculates factorial of a number
ll fat(ll x){
	if (x == 0) return 1;
	return x*fat(x-1)%mod;
}

// Recursive fastexp
ll fastexp(ll b, ll e){
	if (!e) return 1;
	ll ans = fastexp(b, e/2);
	ans = (ans*ans)%mod;
	if (e%2) ans = (ans*b)%mod;
	return ans;
}

// For you to devide a number that is in a modulo(%)
ll invmod(ll b){
	return fastexp(b, mod-2);
}