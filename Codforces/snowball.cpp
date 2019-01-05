//codeforces.com/contest/1099/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
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

	ll w, h, d1, d2, u1, u2;

	cin >> w >> h;
	cin >> u1 >> d1;
	cin >> u2 >> d2;

	for (ll i = h; i >= 0; i--){
		w += i;
		if (i == d1) w = max(0ll, w-u1);
		else if (i == d2) w = max(0ll, w-u2);
	}

	cout << w << endl;
}
