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

vi v;


int main(){

	int n, ho;
	cin >> n >> ho;

	fr(i,n){
		int a, b;
		cin >> a >> b;

		if (i != 0)
			v.pb(-(a-ant));

		v.pb(b-a);
		ant = b;
	}

	int d = 0, ind = 0, st = 0, h = ho;

	while (ind < v.size()){
		if (h < 0){
			h += min(ho, abs(v[st+1]));
			d -= v[st];
			d -= abs(v[st+1]);
			st += 2;
		}	

		if (h - )
	}

}