#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int memo[8][8][8][8][8][8];

int pd(int cnta, int cntb, int cntc, int cntd, int cnte, int now){

	if(now==0)
		return 1;

	int& pdm = memo[cnta][cntb][cntc][cntd][cnte][now];
	if(pdm!=-1)
		return pdm;

	pdm=0;

	for(int a=0;a<=cnta;a++){
		for(int b=0;b<=cntb;b++){
			for(int c=0;c<=cntc;c++){
				for(int d=0;d<=cntd;d++){
					for(int e=0;e<=cnte;e++){
						if(1*a+2*b+3*c+4*d+5*e==now){
							pdm=max(pdm,pd(cnta-a,cntb-b,cntc-c,cntd-d,cnte-e,now-1));
							if(pdm)	return pdm=1;
						}
					}
				}
			}
		}
	}

	return pdm;

}

int main(){
	fastio
	int t; cin >> t;
	ms(memo,-1);
	while(t--){
		string s; cin >> s;
		vi v(6);
		for(auto x : s)
			v[x-'A'+1]++;
		cout << (pd(v[1],v[2],v[3],v[4],v[5],5) ? "YES" : "NO") << "\n";
	}
}
