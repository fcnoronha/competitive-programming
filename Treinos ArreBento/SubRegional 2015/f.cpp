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
#define otp(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vector<ll> lista;
ll memo[100100][10];

ll fat(ll x){
	if(x==1)
		return 1;
	return x*fat(x-1);
}

ll pd(int ind, ll acum){

	if(acum<0)
		return INF;

	if(ind>7){
		if(!acum)
			return 0;
		return INF;
	}

	ll &pdm = memo[acum][ind];
	if(pdm!=-1)
		return pdm;

	return pdm = min( 1 + pd(ind,acum-lista[ind]) , pd(ind+1,acum) );

}

int main(){

	int n; cin >> n;

	int x =1;
	while(x<=8){
		lista.pb(fat(x));
		x++;
	}

	ms(memo,-1);
	cout << pd(0,n) << endl;

}