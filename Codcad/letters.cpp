// codcad.com/problem/129

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

int lis(vector<int> &v){
	vector<int> st; 

	for (int i = 0; i < v.size(); i++){

		vector<int>::iterator it = upper_bound(st.begin(), st.end(), v[i]);

		if (it == st.end()) st.pb(v[i]);

		else *it = v[i];
	}
	return st.size();
}

int main(){
	fastio
		
	string aux;
	cin >> aux;

	vector<int> v;

	fr(i, aux.length()) v.pb(aux[i]-'A');

	cout << lis(v) << endl;
}
