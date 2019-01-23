
// codeforces.com/contest/1100/problem/C
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

const long double PI = acos(-1);

int main(){
	fastio
	
	int n, r;
	cin >> n >> r;

	long double ang = 180.0/n;
	// dbg(sin(45));

	long double ans = (sin(ang*PI/180)*(long double)r)/(1-sin(ang*PI/180));

	cout << setprecision(7) << fixed << ans << endl;
}
