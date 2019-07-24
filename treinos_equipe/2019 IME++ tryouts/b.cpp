#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

string a,b;
int memo[1100][1100];

int pd(int l, int r){

	if(l==a.size() || r==b.size())
		return 0;

	int& pdm = memo[l][r];
	if(pdm!=-1)	return pdm;

	pdm = max(pd(l+1,r),pd(l,r+1));
	if(a[l]==b[r])
		pdm=max(pdm,1+pd(l+1,r+1));
	return pdm;

}

int main(){
	fastio;
	cin >> a >> b;
	ms(memo,-1);
	cout << pd(0,0) << endl;
}
