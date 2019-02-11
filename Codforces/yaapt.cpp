//codeforces.com/contest/1114/problem/B

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
	
	int n, m, k;
	cin >> n >> m >> k;

	ll a[n], aux[n];
	fr(i, n) cin >> a[i], aux[i] = a[i];

	sort(aux, aux+n);
	reverse(aux, aux+n);

	ll mx = 0ll;
	map<ll, int> mp;
	fr(i, m*k) mx += aux[i], mp[aux[i]]++;
	//fr(i, m*k) dbg(aux[i]);

	cout << mx << endl;

	int cnt = 0, t = 0;
	fr(i, n){

		if (mp.find(a[i]) != mp.end() && mp[a[i]] > 0){
			mp[a[i]]--;
			cnt++;
			//dbg(a[i]);
		}

		if (cnt == m){
			cnt = 0;
			t++;
			cout << i+1 << " ";
		}

		if (t == k-1) break;
	}
	cout << endl;
}
