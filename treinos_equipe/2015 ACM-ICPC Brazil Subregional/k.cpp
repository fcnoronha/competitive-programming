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

int memo[2250][2250];

string s;

pii pd(int l, int r){



	pii &pdm=memo[l][r];
	if(pdm!={-INF,-INF})
		return pdm;


}

int main(){

	getline(cin,s);
	int n; cin >> n;
	
	frr(i,n){
		int aux; cin >> aux;
		acum[aux]=1;
	}

	int len = s.size();

	fr(i,2250)
		fr(j,2250)
			memo[i][j]={-1,-1};

	pii ans = {-INF,-INF};

	frr(i,len)
		ans = max(ans,pd(i,i));

	cout << ans.snd << endl;

}