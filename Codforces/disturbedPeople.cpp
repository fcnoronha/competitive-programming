//codeforces.com/contest/1077/problem/B

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

	bool a[n], dis[n];
	fr(i, n) cin >> a[i], dis[i] = 0;

	frr(i, n-2) 
		if (!a[i] && a[i-1] && a[i+1])
			dis[i] = 1;

	int ans = 0;
	frr(i, n-2){

		if (dis[i] && dis[i+2]){
			ans++;
			dis[i] = dis[i+2] = 0;
		}

		if (dis[i]){
			ans++;
			dis[i] = 0;
		}

	}

	cout << ans << endl;
}
