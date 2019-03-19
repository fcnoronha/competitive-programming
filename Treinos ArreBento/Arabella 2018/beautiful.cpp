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

int memo[1010][1010];

int pd(int i, int j){

	if(j<0 || j>i)	return 0;
	if(!i && !j)	return 1;
	int &pdm = memo[i][j];
	if(pdm!=-1)	return pdm;
	return pdm = (pd(i-1,j-1) + pd(i-1,j))%2;
}

int main(int argc, char** argv){

	fastio;

	ms(memo,-1);

	int sz = atoi(argv[1]);
	
	fr(i,sz){
		fr(k, (sz-i)) cout << " ";
		fr(j,sz){
			if(j>i)	break;

			cout << (!pd(i,j) ? ' ' : '1') << " ";
		}
		gnl;
	}


}