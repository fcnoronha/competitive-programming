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

int k, n, m;

char diff[11234];

int main(){

	fastio;
	int t; cin >> t;
	while(t--){
		cin >> n >> m >> k;
		frr(i, n) cin >> diff[i];
		int bigseen = k, count = 0;
		fr(i, m){
			char test; cin >> test;
			if(test == 'A'){
				bigseen = n;
			}
			else{
				int w; cin >> w;
				if(diff[w] == 'S' && w <= bigseen){
					count++;
				}
				bigseen = max(bigseen, w);
			}
		}
		cout << count << endl;
	}

	
}