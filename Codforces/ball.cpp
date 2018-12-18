// https://codeforces.com/problemset/problem/12/D

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

#define MAXN 500009

int bit[MAXN];

int query(int i){
	// max query
	int ans = -1;
	for (; i > 0; i -= i&-i)
		ans = max(ans, bit[i]);
	return ans;
}

void update(int i, int v){
	// max update
	for (; i < MAXN; i += i&-i)
		bit[i] = max(bit[i], v);
	return;
}

typedef struct {
	int b,i,r;
} strutop;

bool comp1(strutop a, strutop b){
	return a.b > b.b;
}

bool comp2(strutop a, strutop b){
	return a.i < b.i;
}

int main(){
	fastio

	ll n;
	cin >> n;

	strutop v[n];

	fr(i,n) cin >> v[i].b;
	fr(i,n) cin >> v[i].i;
	fr(i,n) cin >> v[i].r;

	sort(v, v+n, comp2);

	int k = 1;
	fr(i, n){
		int aux = v[i].i;
		v[i].i = k;
		if (i == n-1 || aux == v[i+1].i) continue;
		k++;
	}
	
	sort(v, v+n, comp1);

	int ans = 0;
	queue<pii> q;
	for (int i = 0; i < n;){

		if (query(MAXN-v[i].i-1) > v[i].r)
			ans++;

		q.push({MAXN-v[i].i, v[i].r});
		i++;

		while (i < n && v[i].b == v[i-1].b){
			if (query(MAXN-v[i].i-1) > v[i].r)
				ans++;
			q.push({MAXN-v[i].i, v[i].r});
			i++;
		}

		while (!q.empty()){
			pii aux = q.front();
			q.pop();
			update(aux.f, aux.s);
		} 
	}

	cout << ans << endl;

	// https://codeforces.com/blog/entry/44775
}
