// codeforces.com/contest/1096/problem/C

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
	
	int t;
	cin >> t;

	while (t--){
		int ang, ango;
		cin >> ang;

		ango = ang;

		int gcd = __gcd(180, ang);

		ang /= gcd;
		int ans = 180/gcd;

		if (ang + 1 == ans) ans *= 2;

		cout << ans << endl;
	}
}
