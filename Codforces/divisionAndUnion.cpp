// codeforces.com/contest/1101/problem/C

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

	int t;
	cin >> t;

	while (t--){

		int n;
		cin >> n;

		pii seg[n];
		int ls[n];

		fr(i, n) cin >> ls[i] >> seg[i].f, seg[i].s = i;

		sort(seg, seg+n);

		int minl = ls[seg[n-1].s], x = -1;

		for (int i = n-2; i >= 0; i--){

			if (seg[i].f < minl){

				x = seg[i].f;
				break;
			}

			minl = min(minl, ls[seg[i].s]);
		}

		if (x == -1){
			p(-1);
			continue;
		}

		fr(i, n){
			if (ls[i] >= minl) cout << 1;
			else cout << 2;
			cout << " ";
		}
		cout << endl;
	}		
}
