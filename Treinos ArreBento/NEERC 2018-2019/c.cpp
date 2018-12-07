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
#define ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) fastio

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int freq[2100100];

int main(){


	int n; cin >> n;

	vi aux;

	fr(i,n){
		int x; cin >> x;
		aux.pb(x);
	}	

	int base = aux[0];

	while(base%2==0)	base/=2;

	fr(i,n){
		int lol = aux[i];
		while(lol%2==0)
			lol/=2;
		if(lol!=base){
			cout << -1 << endl;
			return 0;
		}
	}

	fr(i,n){
		aux[i]/=base;
		aux[i]=31-__builtin_clz(aux[i]);
		freq[aux[i]]++;
	}

	int ini=0;
	int cost = 0;

	while(n>1){

		if(freq[ini]%2){
			freq[ini]++;
			cost++;
			n++;
		}

		freq[ini+1]+=freq[ini]/2;
		
		n-=freq[ini];
		n+=freq[ini]/2;
		
		ini++;
	
	}

	cout << cost << endl;

}