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
typedef pair<ll,ll> pll;
typedef vector<pll> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

vii p;

int main(){
	ll n, ans, delta_up, delta_down, x, y;

	cin >> n;
	while(n--){
		cin >> x >> y;
		p.pb({x,y});
	}
	sort(p.begin(), p.end());

	ans = 0;

	fr(i, p.size()){
		delta_up = LLONG_MAX;
		delta_down = LLONG_MIN;
		for(int j = i+1; j < p.size(); j++){
			
				
			if (p[i].snd < p[j].snd && p[j].snd < delta_up){
				ans++; 
				delta_up = p[j].snd;
			}
			if (p[i].snd > p[j].snd && p[j].snd > delta_down){
				ans++; 
				delta_down = p[j].snd;
			}
		
		}
	}

	cout << ans << endl;
}