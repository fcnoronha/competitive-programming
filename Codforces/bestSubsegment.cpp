//codeforces.com/contest/1117/problem/A

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

bool v[100009];

int main(){
	fastio
		
	int n;
	cin >> n;

	int a[n], mx = 0;
	fr(i, n)
		cin >> a[i], mx = max(mx, a[i]);

	int ans = 1;
	fr(i, n){
		if (a[i] != mx || v[i]) continue;
		
		v[i] = true;
		int aux = 1;
		int k = i+1;
		while (k < n && a[k] == mx)
			aux++, v[k] = 1, k++; 

		k = i-1;
		while (k >= 0 && a[k] == mx)
			aux++, v[k] = 1, k--;

		ans = max(ans, aux);	
	}

	cout << ans << endl;
}
