#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef unsigned long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

// Function to find the sum 
// of all divisors of all 
// numbers from 1 to N 
ll solve(ll n) 
{ 

	// Stores the sum 
	ll s = 0; 

	for (ll l = 1; l <= n;) { 

		ll p = (n / l); 
		// Marks the last poll of 
		// occurence with same count
		ll r = n / p; 
        ll plc = ((l + r)*(r - l + 1ll))/2ll;
        s += plc*p;
		l = r + 1ll; 
	} 

	// Return the result 
	return s; 
} 

// Driver Code 
int main(){
    ll a, b; scanf("%llu%llu", &a, &b);
    ll plc = 0;
    if(a != 1) plc = solve(a-1);
    printf("%llu\n", solve(b) - plc);
}
