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

int main(){
	
	int h,w;
	cin >> h >> w;
	vi prim,seg;
	fr(i,h){
		int aux; cin >> aux;
		prim.pb(aux);
	}
	fr(i,h){
		int aux; cin >> aux;
		seg.pb(aux);
	}

	double ans = 1000000000.0;

	fr(i,h){
		double lol = w - (prim[i]+seg[i]);
		lol=lol/2;
		ans=min(ans,lol);
	}

	cout << setprecision(15) << fixed;
	cout << ans << endl;


}