// codeforces.com/contest/1055/problem/A

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
	
	int n, s;
	cin >> n >> s;

	int a[n], b[n];
	fr(i, n) cin >> a[i];
	fr(i, n) cin >> b[i];

	s--;
	if ((a[s] == 0 && b[s] == 0) || a[0] == 0){
		p(NO);
		return 0;
	}

	if (a[s]){
		p(YES);
		return 0;
	}

	fr(i, n){
		if (i == 0) i = s+1;
		if (b[i] && a[i]){
			p(YES);
			return 0;
		}
	}

	p(NO);
}