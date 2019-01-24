// codeforces.com/contest/1108/problem/A

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
	
	int q;
	cin >> q;

	while (q--){

		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		if (l1 == r1){

			if (l2 == l1) cout << l1 << " " << r2 << endl;
			else cout << l1 << " " << l2 << endl;
		}

		else if (l2 == r2){

			if (l1 == l2) cout << r1 << " " << l2 << endl;
			else cout << l1 << " " << l2 << endl;
		}

		else {

			if (r1 == l2) cout << r1 << " " << r2 << endl;
			else cout << r1 << " " << l2 << endl;

		}

	}
}
