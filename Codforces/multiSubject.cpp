// https://codeforces.com/contest/1082/problem/C

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
typedef pair<ll,ll> pii;
typedef vector<ll> vi;

int main(){
	ll n, m;
	cin >> n >> m;

	vector<pii> oi;

	ll a, b;
	fr(i, n){
		cin >> a >> b;
		oi.pb({b,a});
	}

	frr(i, m){
		oi.pb({INT_MIN, i});
	}

	sort(oi.begin(), oi.end());
	reverse(oi.begin(), oi.end());

	vector<ll> ind(m+n, 0); // indice	de cada coisa 
	vi h(m+n, 0); // acumulado geral
	vi ac(m+n, 0); // acumulado de cada tipo

	fr(i, oi.size()){
		ll j = oi[i].s; // type
		ll ho = oi[i].f; // skill

		ll ola = ind[j];

		if(ho == INT_MIN){
			h[ola] -= ac[j];
			ac[j] = 0;
		}

		else{
			h[ola] = h[ola] + ho;
			ind[j]++;
			ac[j] += ho;
		}

		if(ac[j] < 0){
			h[ola] -= ac[j];
			ac[j] = 0;
		}
	}

	ll ans = 0, sum = 0;
	fr(i, h.size()){
		sum += h[i];
		ans = max(ans, sum);
	}

	ans = max(0ll, ans);
	cout << ans << endl;

}
