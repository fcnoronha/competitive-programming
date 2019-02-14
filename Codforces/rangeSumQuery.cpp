// codeforces.com/group/BDIXyZZHhT/contest/205512/problem/D

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

#define MAXN 100009 
#define MAXSQRT 1000

ll a[MAXN];
ll b[MAXSQRT];
int bsz; 

void update(int i, ll v){

	int bn = i/bsz;
	b[bn] += v - a[i];
	a[i] = v;
}

ll query(int l, int r){

	ll sum = 0;
	while (l < r && l%bsz != 0 && l != 0)
		sum += a[l++];

	while (l+bsz <= r){
		sum += b[l/bsz];
		l += bsz;
	}

	while (l <= r)
		sum += a[l++];

	return sum;
}

void prepro(int n){

	int bidx = -1;
	bsz = sqrt(n);

	for (int i = 0; i < n; i++){
		
		bidx += (i%bsz == 0);

		b[bidx] += a[i];
	}
}


int main(){
	fastio
	
	int n, q;
	cin >> n >> q;

	fr(i, n) cin >> a[i];

	prepro(n);

	fr(i, q){
		char op;
		ll l, r;
		cin >> op >> l >> r;

		if (op == '?')
			cout << query(l-1, r-1) << endl;

		else 
			update(l-1, r);
	}	
}
