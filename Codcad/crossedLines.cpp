// codcad.com/problem/73

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

int ic(vector<int> &v){

	int inv = 0;

	if (v.size() == 1) return 0;

	vector<int> u1, u2;

	for (int i = 0; i < v.size()/2; i++)
		u1.push_back(v[i]);

	for (int i = v.size()/2; i < v.size(); i++)
		u2.push_back(v[i]);

	inv += ic(u1);
	inv += ic(u2);

	u1.push_back(INT_MAX);
	u2.push_back(INT_MAX);

	int ini1 = 0, ini2 = 0;

	for (int i = 0; i < v.size(); i++){

		if (u1[ini1] <= u2[ini2])
			v[i] = u1[ini1++];

		else {
			v[i] = u2[ini2++];
			inv += u1.size() - ini1 - 1;
		}
	}
	return inv;
}


int main(){
	fastio
	
	int n;
	cin >> n;

	vi v(n);
	fr(i, n) cin >> v[i];

	cout << ic(v) << endl;
}
