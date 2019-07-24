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
	
	int T;
	cin >> T;
	fr(i, T){
		int N, pos, gs = 1, done = 0, out = 0;
		cin >> N >> pos;
		while(not(done)){
			if(gs){
				if(pos%2) out += pos/2 + pos%2, done = 1;
				else{
					out += (N/2 + N%2);
					if(N%2) gs = 0;
					else gs = 1;
					N = N/2;
					pos = pos/2;
				}
			}
			else{
				if(not(pos%2)) out += pos/2, done = 1;
				else{
					out += N/2;
					if(N%2) gs = 1;
					else gs = 0;
					N = N/2 + N%2;
					pos = pos/2 + pos%2;
				}
			} 
		}
		printf("%d\n", out);
	}
}