// codeforces.com/contest/1108/problem/C

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
	string colors;
	cin >> n >> colors;

	pii ans = {INT_MAX, 0};
	string opc[6] = {"BRG", "BGR", "GRB", "GBR", "RGB", "RBG"};

	fr(j, 6){

		string p = opc[j];
		int aux = 0;

		fr(i, n)
			if (colors[i] != p[i%3]) aux++;

		if (aux < ans.f) ans = {aux, j};		
	}

	cout << ans.f << endl;
	fr(i, n) cout << opc[ans.s][i%3];
	cout << endl;
}
