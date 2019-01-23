// codeforces.com/contest/1101/problem/A

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

	int q, l, r, d;
	cin >> q;

	while (q--){
		cin >> l >> r >> d;

		if (d < l || d > r){
			cout << d << endl;
			continue;
		}

		if (r%d == 0) r++;

		int aux = ceil(r/(d*1.0));
		cout << d*aux << endl;
	}
}
