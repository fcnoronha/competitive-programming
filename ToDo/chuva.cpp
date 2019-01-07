// codcad.com/problem/189

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
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

#define MAXN 100009

int bit[100009];

int query(int i){
	int sum = 0;
    for (; i > 0; i -= i&-i)
    	sum += bit[i];
    return sum;
}

void update(int x, int i){
	for (; i <= MAXN; i += i&-i)
		bit[i] += x;
}

int main(){
	fastio
	
	int n;
	cin >> n;

	int a[n], b[n];

	fr(i, n) cin >> a[i], b[i] = a[i];

	sort(a, a+n);

	int cnt = 1;
	map<int, int> m;
	fr(i,n){
		if (i > 0 && a[i] == a[i-1]) continue;
		m[a[i]] = cnt++;
	}

	fr(i,n){
		b[i] = m[b[i]];
		update(1, b[i]);
		// dbg(b[i]);
	}

	int ans = 0;
	fr(i, n){

		update(-1, b[i]);

		if ( (query(cnt) - query(b[i]-1) ) <= 0){
			//dbg(i);
			continue;
		}

		if (i > 0 && i < n-1 && b[i-1] > b[i]) ans++;
	
		int act = b[i]; dbg(act);
		i++;
		while (i < n && b[i] < act){
			ans++;
			i++;
		}

		if (i == n && act > b[i-1]){
			i--;
			ans--; 
			while (i >= 0 && b[i] == b[i-1]) i--, ans--;
		}
	}

	cout << ans << endl;
}
