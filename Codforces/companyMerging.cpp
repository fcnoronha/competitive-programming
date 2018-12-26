// https://codeforces.com/contest/1090/problem/A

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

typedef struct {
	ll qtd, sum, mx;
} felipegato;

int main(){
	ll n; 
	cin >> n;

	felipegato oi[n];

	int mxzao = 0;
	fr(i, n){
		int q;
		cin >> q;
		int aux = 0, mx = 0;
		fr(j, q){
			int x;
			cin >> x;
			aux += x;
			mx = max(mx, x);
		}
		mxzao = max(mxzao, mx);
		oi[i] = {q, aux, mx};
	}

	ll ans = 0;
	fr(i, n){
		ll aux = mxzao - oi[i].mx;
		aux *= oi[i].qtd;
		ans += aux;
	}	

	cout << ans << endl;
}
