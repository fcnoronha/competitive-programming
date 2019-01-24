// codeforces.com/contest/1104/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio
	
	string s;
	cin >> s;

	bool ver = false, hor = false;

	fr(i, s.length()){

		if (s[i] == '1'){

			if (ver) {
				p(4 3);
				ver = false;
			}

			else {
				p(4 1);
				ver = true;
			}
		}

		else {

			if (hor){
				p(3 4);
				hor = false;
			}

			else {
				p(1 4);
				hor = true;
			}
		}
	}
}
