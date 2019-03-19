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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;

ll go(ll x){

	if(x==0)	return 1;
	if(x==1)	return 2;
	if(x==2)	return 2;

	int logi = 63 - __builtin_clzll(x);
	x^=(1ll<<logi);
	return 2ll*go(x);
	
}

int main(){

	fastio;

	int t; cin >> t;

	while(t--){
		ll x; cin >> x;
		cout << x+1ll-go(x) << endl;

	}


}