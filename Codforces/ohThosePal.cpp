//codeforces.com/contest/1064/problem/C

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
	string str;

	cin >> n >> str;

	vi freq(27, 0);

	fr(i, n)
		freq[str[i]-'a']++;
	
	fr(i, 26) while (freq[i]-- > 0) cout << char('a'+i);

	cout << endl;	
}
