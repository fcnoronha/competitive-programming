//codeforces.com/contest/1106/problem/A

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
	cin >> n;

	string str[n];
	fr(i, n) cin >> str[i];

	int ans = 0;
	fr(i, n)
		fr(j, n)
			if (i < n-2 && j < n-2 && str[i][j] == 'X' && str[i][j+2] == 'X' &&
				str[i+1][j+1] == 'X' && str[i+2][j] == 'X' && str[i+2][j+2] == 'X')
					ans++;

	cout << ans << endl;
}
