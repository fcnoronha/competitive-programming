// www.spoj.com/problems/FENTREE/

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
typedef vector<ll> vi;

#define MAXN 1000009

ll bit[MAXN];

ll query(ll i){
	ll sum = 0;
    for (; i > 0; i -= i&-i) 
    	sum += bit[i];
    return sum;
}

void update(ll x, ll i){
	for (; i < MAXN; i += i&-i)
		bit[i] += x;
}

int main(){
	fastio

	ll n, q;
	cin >> n;

	ll x;
	frr(i, n){
		cin >> x;
		update(x,i);
	}

	cin >> q;
	ll r, l;
	char qu;
	fr(i, q){
		cin >> qu >> l >> r;

		if (qu == 'u')
			update(r, l);

		else {
			cout << query(r) - query(l-1) << endl;
		}
	}

}
