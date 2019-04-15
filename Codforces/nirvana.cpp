// codeforces.com/contest/1143/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

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
typedef long double ld;

int main(){
	fastio

	string n;
	cin >> n;

	if (n.length() == 1){
		cout << n << endl;
		return 0;
	}

	ll ans = 1;
	for (int j = 0; j < n.length(); j++)
		ans *= (n[j]-'0');

	for (int i = n.length(); i >= 0; i--){

		if (n[i] != '9'){
			if (i > 0){
				n[i] = '9';
				if (n[i-1] > '1') n[i-1]--;
			}
		}

		ll aux = 1;
		for (int j = 0; j < n.length(); j++){
			aux *= (n[j]-'0');
		}

		ans = max(ans, aux);
	}

	cout << ans << endl;
}
