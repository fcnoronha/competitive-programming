// codeforces.com/contest/1105/problem/A

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
	
	int n;
	cin >> n;

	int a[n];
	fr(i, n) cin >> a[i];

	int ansv[1000009];
	int ans = INT_MAX;

	frr(i, 100){
		int aux = 0;

		fr(j, n){

			if (abs(a[j]-i) <= 1) continue;

			if (a[j] > i) aux += a[j]-i-1;
			else aux += i-a[j]-1;
		}

		if (aux < ans) ansv[aux] = i;
		ans = min(ans, aux);
	}

	cout << ansv[ans] << " " << ans << endl;
}
