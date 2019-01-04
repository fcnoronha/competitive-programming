// codeforces.com/contest/988/problem/D

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(long long int i=0;i<n;i++)
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

bool isPower(ll x){
	if (x == 2048ll) p(OI);
	return (x != 0 && (x&(x-1)) == 0);
}

int main(){
	fastio
	// hehehe
	ll n;
	cin >> n;

	vl num;
	fr(i, n){
		ll x;
		cin >> x;

		num.pb(x);
	}

	sort(num.begin(), num.end());

	vl powers;
	fr(i, 31) powers.pb(1ll << i);

	fr(i, n){

		fr(j, 31){

			ll aux1 = num[i] + powers[j];
			ll aux2 = num[i] - powers[j];

			//dbg(aux1); dbg(aux2); dbg(num[i]); p(-);

			if (binary_search(num.begin(), num.end(), aux1) &&
				binary_search(num.begin(), num.end(), aux2)){
				p(3);
				cout << aux1 << " " << num[i] << " " << aux2 << endl;
				return 0;
			}
		}

	}

	fr(i, n){

		fr(j, 31){

			ll aux1 = num[i] + powers[j];

			if (binary_search(num.begin(), num.end(), aux1)){
				p(2);
				cout << aux1 << " " << num[i] << endl;
				return 0;
			}
		}
	}

	p(1);
	cout << num[0] << endl;
}
