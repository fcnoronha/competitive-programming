// https://vn.spoj.com/problems/KMEDIAN/

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

#define MAXN 300009
int bit[MAXN];

int query(int i){
	i += 100009;
	int sum = 0;
	for (; i > 0; i -= i&-i)
		sum += bit[i];
	return sum;
}

int update(int i, int v){
	i += 100009;
	for (; i < MAXN; i += i&-i)
		bit[i] += v;
}

int main(){
	ll n, x;
	cin >> n >> x;

	int a[n];
	fr(i, n){
		ll aux;
		cin >> aux;
		
		a[i] = -1;
		if (aux >= x) a[i] = 1;
	}

	update(0, 1); // Because we want >0 subarrays

	ll ans = 0, cnt = 0;
	// BIT itself
	fr(i, n){ 
		cnt += a[i];
		ans += query(cnt);
		update(cnt, 1);
	}

	cout << ans << endl;
}
