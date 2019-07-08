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

map<char,int> m;	vector<char> aux = vector<char>({'A','H','I','M','O','T','U','V','W','X','Y'});

void go(){

	int k;
	string s;
	cin >> k >> s;

	reverse(all(s));

	int v[3030];
	ms(v,-1);

	int n=s.size();

	for(int i=1;i<=n;i++)
		v[i]=m[s[i-1]];

	while(k){
		if(k<11){
			v[1]+=k;
			k=0;
			break;
		}
		ll ini=1;
		ll base = 1;
		while(base*11<=k && ini+1<=n){
			ini++;
			base*=11ll;
		}
		ll poe = k/base;
		v[ini]+=poe;

		k=k%base;
	}

	int ini=1;

	string ans;

	while(v[ini]!=-1){
		if(v[ini]>10){
			int passa = v[ini]/11;
			v[ini+1]+=passa;
			v[ini]%=11;
		}
		ans.pb(aux[v[ini]]);
		ini++;
	}
	reverse(all(ans));

	cout << ans << "\n";
}

int main(){
	fastio
	int t; cin >> t;

	for(int i=0;i<11;i++)
		m[aux[i]]=i;
	while(t--)	go();
}
