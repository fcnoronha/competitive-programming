// codeforces.com/contest/1096/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
#define p(x) cout << #x << endl

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
	string s;

	cin >> n >> s;

	const ll mod = 998244353;
	ll ans;

	ll i = 1, f = n-2;
	while (s[i] == s[i-1]) i++;
	while (s[f] == s[f+1]) f--;
	f = n - f - 1; 

	if (s[0] == s[n-1])
		ans = ((f+1)*(i+1))%mod;

	else 
		ans = (f+i+1)%mod;

	cout << ans << endl;		
}
