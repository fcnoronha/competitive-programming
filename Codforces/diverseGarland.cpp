// codeforces.com/contest/1108/problem/D

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
	string c;

	cin >> n >> c;

	int ans = 0;
	fr(i, n){
		i += (i == 0);

		set<char> aux;
		aux.insert('G');
		aux.insert('R');
		aux.insert('B');

		if (c[i] == c[i-1]){

			if (i < n-1)
				aux.erase(c[i+1]);

			aux.erase(c[i-1]);

			c[i] = *(aux.begin());
			ans++;
		}
	}

	cout << ans << endl << c << endl;
}
