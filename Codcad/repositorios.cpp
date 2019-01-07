// codcad.com/problem/59

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
	
	int c, n;
	cin >> c >> n;

	map<int, int> ver;

	int p, v;
	fr(i, c){
		cin >> p >> v;

		ver[p] = max(ver[p], v);
	}

	set<int> ans;
	fr(i, n){
		cin >> p >> v;

		if (ver[p] < v){
			ans.insert(p);
			ver[p] = v;
		}
	}

	int t = ans.size();
	fr(i, t){

		int p = *(ans.begin());
		ans.erase(p);

		cout << p << " " << ver[p] << endl;

	}
}
