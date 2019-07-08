#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int v[30];
int k[100100];

int ehPrimo(int x){
	for(int i = 2; i*i <= x; i++){
		if(x%i == 0) return 0;
	}
	return 1;
}

int main(){
	fastio

	int t;
	cin >> t;

	v[2] = 1;
	for(int i  = 3; i<25; i++){
		if(ehPrimo(i)) {
			v[i] = 1;
		}
	}

	k[2] = 0;
	for(int i = 3; i< 100100; i++){
		if(v[__builtin_popcount(i)]) k[i] = 1;
	}

	for(int i = 1; i<100100; i++){
		k[i] += k[i-1];
	}
	while(t--){
		int l, r;
		cin >> l >> r;
		if(l==0) cout << k[r] << "\n";
		else cout << k[r] - k[l-1] << "\n";
	}
}
