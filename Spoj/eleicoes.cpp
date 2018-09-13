// https://br.spoj.com/problems/ELEICOES/

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;

int main(){
	ll n, x;

	cin >> n;
	map<ll,ll> v;

	fr (i, n){
		cin >> x;
		v[x]++;
	}

	ll mxv = 0, ans = 0;
	for (map<ll,ll>::iterator it = v.begin(); it != v.end(); it++){
		if (it->s > mxv){
			mxv = it->s;
			ans = it->f; 
		}
	}	
	cout << ans << endl;
}
