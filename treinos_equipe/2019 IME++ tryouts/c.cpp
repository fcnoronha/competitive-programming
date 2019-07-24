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

int main(){

	fastio

	ll n,low,d; cin >> n>>low>>d;

	ll ans = 0;

	vector<ll> skill;
	fr(i,n){
		int x; cin >> x;
		skill.pb(x);
	}

	fr(i,1<<n){
		ll mx = 0;
		ll mn = 0x3f3f3f3f;
		ll cnt = 0;
		ll cur_skill=0;
		for(ll j=0;j<n;j++){
			if(((1<<j)&i)==0 )
				continue;
			cnt++;
			cur_skill+=skill[j];
			mx=max(mx,skill[j]);
			mn=min(mn,skill[j]);
		}
		if(cnt && abs(mx-mn)<=d && cur_skill>=low)
			ans++;
	}

	cout << ans << endl;

}
