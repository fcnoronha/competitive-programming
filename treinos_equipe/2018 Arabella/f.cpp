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

int freq[26];

int singles, pairs, min_pair = INF;

int main(){

	fastio;
	int t; cin >> t;
	while(t--){
		fr(i, 26){
			cin >> freq[i];
			if(freq[i] == 1) singles++;
			if(freq[i] > 1) {
				pairs++; 
				min_pair = min(min_pair, freq[i]);
			}
		}
		if(singles == 0){
			cout << 2*pairs << " " << (min_pair!=INF?min_pair/2:0) << endl;
		}
		else{
			cout << 2*pairs + 1 << " " << ( pairs!=0 ? min(min_pair/2, singles)  : singles)<< endl;	
		}
		pairs = singles = 0;
		min_pair = INF;		
	}

	
}