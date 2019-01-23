// codeforces.com/contest/1101/problem/E

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

	int w, h, maxw = 0, maxh = 0;
	char op;

	while (n--){

		cin >> op >> h >> w;

		if (h > w) swap(h, w);

		if (op == '+'){
			maxw = max(maxw, w);
			maxh = max(maxh, h);
		}

		else {
			// dbg(maxw);
			if (h >= maxh && w >= maxw) p(YES);
			else p(NO);
		}
	}
}
