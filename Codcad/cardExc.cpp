// codcad.com/problem/60

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
	
	int a, b;
	cin >> a >> b;

	set<int> sa;
	set<int> sb;

	vi va;
	vi vb;
	fr(i, a){
		int x;
		cin >> x;
		sa.insert(x);
		va.pb(x);
	}

	fr(i, b){
		int x;
		cin >> x;
		sb.insert(x);
		vb.pb(x);
	}

	int auxa = 0, auxb = 0;
	for(set<int>::iterator it = sa.begin(); it != sa.end(); ++it)
		if (sb.find(*it) == sb.end())
			auxa++;

	for(set<int>::iterator it = sb.begin(); it != sb.end(); ++it)
		if (sa.find(*it) == sa.end())
			auxb++;

	cout << min(auxa, auxb) << endl;
}
