// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1480

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

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

#define MAXN 1000009
vector<bool> isPrime(MAXN, 1);

int main(){
	fastio
	
	for(int i = 2; i < MAXN; i++){

		for (int j = i+i; j < MAXN; j += i)	
			isPrime[j] = 0;
	}

	vl ans;
	for(int i = 2; i < MAXN; i++){
 
		if (!isPrime[i]) continue;

		for (ll p = 2; (ll)pow(i, p) < 1e12; p++) ans.pb((ll)pow(i, p));
	}

	sort(all(ans));
	
	int n;
	cin >> n;

	while (n--){

		ll a, b;
		cin >> a >> b;

		auto anss = (upper_bound(all(ans), b) - lower_bound(all(ans), a));

		cout << anss << endl;
	}
}
