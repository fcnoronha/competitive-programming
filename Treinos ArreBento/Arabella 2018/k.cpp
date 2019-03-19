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

string s;

void go(){

	int n; string a,b;
	cin >> n >> a >> b;

	if(a==b){
		cout << "YES" << endl;
		return;
	}

	string x,y;

	fr(i,n){
		if(a[i]!=b[i]){
			x.pb(a[i]);
			y.pb(b[i]);
		}
	}

	string aux;

	aux+=y[y.size()-1];
	fr(i,y.size()-1)	aux+=y[i];

	if(aux==x){
		cout << "YES" << endl;
		return;
	}

	cout << "NO" << endl;

}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	go();
	
}