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


int n,c;
ll memo[200200][33];
int v[200200];

ll pd(int ind, int state){

	if(ind>n)
		return 0;

	ll &pdm=memo[ind][state];
	if(pdm!=-1)
		return pdm;

	if(state==0)
		return pdm=max( -1*v[ind] - c + pd(ind+1,1) , pd(ind+1,0) );
	else
		return pdm=max( v[ind] + pd(ind+1,0) , pd(ind+1,1) );

}

int main(){

	cin >> n >> c;
	
	frr(i,n)
		cin >> v[i];

	ms(memo,-1);
	cout << pd(1,0) << endl;


}