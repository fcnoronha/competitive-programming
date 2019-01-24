// codeforces.com/contest/1104/problem/B

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

	stack<char>	piu;

	int ans = 0;

	fr(i, s.length()){

		if (piu.size() == 0 || piu.top() != s[i]) piu.push(s[i]);

		else {
			piu.pop();
			ans = !ans;
		}
	}

	if (ans) p(Yes);
	else p(No);	
}
