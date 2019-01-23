// codeforces.com/contest/1101/problem/B

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
	
	string s;
	int sl;

	cin >> s;
	sl = (int)s.length();

	int l = 0, r = sl-1;

	while (l < sl && s[l] != 91) l++;

	while (l < sl && s[l] != 58) l++;

	if (l == sl){
		p(-1);
		return 0;
	}

	while (r >= 0 && s[r] != 93) r--;

	while (r >= 0 && s[r] != 58) r--;

	if (r <= l){
		p(-1);
		return 0;
	}

	int ans = 4;
	for (int i = l; i < r; i++) 
		if (s[i] == 124)
			ans++;

	cout << ans << endl;
}
