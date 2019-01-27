// codeforces.com/contest/1107/problem/A

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
	
	int q;
	cin >> q;

	while (q--){

		int n;
		cin >> n;

		string s;
		cin >> s;

		if (n == 2 && s[0] >= s[1]){
			p(NO);
			continue;
		}

		p(YES);
		p(2);
		cout << s[0] << " ";
		frr(i, n-1) cout << s[i];
		cout << endl;
	}
}
