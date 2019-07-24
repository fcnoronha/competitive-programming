#include "bits/stdc++.h"
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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vector<ll> primsc;

int main(){
	ll n, ans = 0;
	vector<ll> a(50002, llINF);
	vector<ll> pde(50002, llINF);
	vector<ll> pdd(50002, llINF);

	cin >> n;
	pdd[0] = 1;
	pde[n-1] = 1;

	fr(i, n) cin >> a[i];

	frr(i, n-1) pdd[i] = min(a[i], pdd[i-1]+1);

	for(int i = n-2; i >= 0; i--) pde[i] = min(a[i], pde[i+1]+1);

	for(int i = 1; i < n-1; i++)
		ans = max(ans, min({pde[i], pdd[i], a[i]}));

	cout << ans << endl; 
}