// codcad.com/problem/167

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(long long int i=0;i<n;i++)
#define frr(i,n) for(long long int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
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

ll kfat(ll n, ll k, ll m){
	if ((n - (m*k)) < 1) return 1ll;

	return (n - (m*k))*kfat(n, k, m+1);
}

int main(){
	fastio
	
	ll memo[101][21];
	frr(i, 100)
		frr(j, 20)
			memo[i][j] = kfat(i, j, 0);

	int n;
	cin >> n;

	fr(i, n){
		string aux;
		cin >> aux;

		int a = 0, b = 0, num = 0;
		fr(j, aux.length()){
			if(aux[j] == '!') b++;
			else a++;
		}

		int ca = a;
		fr(j, ca){
			num += (aux[j]-'0')*pow(10, --a);
		}

		cout << memo[num][b] << endl;
	}
}
