// www.codcad.com/problem/57

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

bool comp(vector<string> a, vector<string> b){
	return a.size() < b.size();
}

int main(){
	fastio

	int n, t;
	cin >> n >> t;

	pair<int, string> v[n];
	fr(i, n)
		cin >> v[i].s >> v[i].f;

	sort(v, v+n);
	
	vector<string> porra[t];
	pii tamind[t];
	fr(i, t){
		for (int j = i; j < n; j+= t)
			porra[i].pb(v[j].s);

		sort(porra[i].begin(), porra[i].end());
		tamind[i] = {porra[i].size(), i};
	}

	sort(tamind, tamind+t);
	reverse(tamind, tamind+t);

	fr(i, t){
		cout << "Time " << i+1 << endl;

		int j = tamind[i].s;
		for (auto u : porra[j]) cout << u << endl;
		cout << endl;
	}

}
