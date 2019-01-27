// codeforces.com/contest/1107/problem/C

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

int main(){
	fastio
	
	int n, k;
	cin >> n >> k;

	ll s[n];
	fr(i, n) cin >> s[i];

	string a;
	cin >> a;

	vl aux;
	int cnt = 1;
	ll ans = 0ll;

	frr(i, n){

		if (i < n && a[i] == a[i-1]){

			cnt++;
			continue;
		}

		aux.clear();

		for (int j = i - cnt; j < (i); j++) aux.pb(s[j]);
		sort(all(aux));
		reverse(all(aux));

		// pv(aux);

		fr(j, min(k, (int)aux.size())) ans += aux[j];
		cnt = 1;
	}

	cout << ans << endl;

}
