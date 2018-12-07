// https://codeforces.com/gym/101911

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
#define ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) fastio

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int n, m, d, prox[212345],  ans[212345], peguei[212345];
vii v;

int main(){

	scanf("%d%d%d", &n, &m, &d);

	fr(i, n){
		int aux; scanf("%d", &aux);
		v.pb(mp(aux,i));
	}

	sort(v.begin(), v.end());

	fr(i,n)
		prox[i] = lower_bound(all(v),mp(v[i].fst+d+1,0))-v.begin();

	int days = 1;
	int ini = 0;
	int i = 0;

	int amt = 0;
	
	while(ini<m){

		while(peguei[ini] && ini<n)
			ini++;

		i=ini;

		while(i<n){
			ans[v[i].snd]=days;
			peguei[i]=1;
			i=prox[i];
			amt=max(amt,days);
		}

		ini++;
		days++;

	}

	cout << amt << endl;

	fr(i,n)	cout << ans[i] << " ";
	gnl;


}	
