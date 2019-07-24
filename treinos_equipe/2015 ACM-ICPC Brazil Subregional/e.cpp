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

pll solve(ll left, ll sz){

	dbg(left); dbg(sz);
	if(left<=sz)
		return {0,left};

	left -= (sz);
	
	dbg(left); olar;

	if(left < sz)
		return {left, sz-1};
	
	left -= (sz - 1);
	dbg(left); olar;
	
	if(left < sz)
		return {sz-1, sz - left};

	left -= (sz - 1);
	dbg(left); olar;

	return { sz - left - 1, 0};
	
}

int main(){
	ll N, B, x = 0, left; cin >> N >> B;
	while(4*N*x - (x-1)*x - 4*(x+1) <= B){
		left = B - (4*N*x - (x-1)*x - 4*(x+1)); 
		x++;
		//otp(x); otp(left);
	}
	x--;
	dbg(x); dbg(left); dbg(N-2*x);
	pll ans = {2+x,1+x};
	dbg(ans.fst); dbg(ans.snd);

	pll aux = solve(left, N-2*x);
	dbg(aux.fst); dbg(aux.snd);
	ans.fst += aux.fst; ans.snd += aux.snd;
	cout << ans.fst << " " << ans.snd << endl;

}