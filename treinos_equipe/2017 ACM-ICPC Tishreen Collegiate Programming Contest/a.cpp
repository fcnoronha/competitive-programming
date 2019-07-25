//codeforces.com/gym/101915

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x);
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vll pot10;


int main(){
	ll base = 1;
	fr(i, 17){
		pot10.pb(base);
		base *= 10;
	}

	ll t; scanf("%lld", &t);
	while(t--){
		ll n, x; scanf("%lld%lld", &n, &x);
		ll pos = upper_bound(all(pot10), x)- pot10.begin();

		ll num = pot10[pos];
		ll ans = 0;

		while(n > (num - x)*pos){
			ans += (num - x);
			n -= (num - x)*pos;
			x = num;
			pos++;
			num *= 10;

		}

		if(n == 0){
			printf("%lld\n", ans);
		}
		else{
			if(n%pos != 0) printf("-1\n");
			else printf("%lld\n", ans + n/pos);
		}

	}

}
