// codeforces.com/contest/1121/problem/A

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

	int p[n];
	fr(i, n) cin >> p[i];

	int s[m+2], aux[n];
	ms(s, -1);
	fr(i, n){
		int x;
		cin >> x;

		aux[i] = x;
		if (s[x] == -1 || p[i] > p[s[x]])
			s[x] = i;
	}

	int ans = 0;
	fr(i, k){
		int id;
		cin >> id;
		id--;
		
		if (p[id] < p[s[aux[id]]])
			ans++;
	}

	cout << ans << endl;
}
