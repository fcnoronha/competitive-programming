//codeforces.com/contest/1163/problem/B1

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

#define maxn 200000
int freq[maxn], bit[maxn], a[maxn];

int query(int i){
	int sum = 0;
    for (; i > 0; i -= i&-i)
    	sum += bit[i];
    return sum;
}

void update(int x, int i){
	for (; i <= maxn; i += i&-i)
		bit[i] += x;
}

int main(){
	fastio

	int n; cin >> n;

	int aux;
	fr(i, n) {
		cin >> aux;

		a[i] = ++freq[aux];
	}

	int ans = 0;
	fr(i, n) {

		int f = a[i];

		update(1, f);
		// Letting only the maximum frequency in BIT
		if (f > 1)
			update(-1, f-1);

		// For me to be able to make this (i+1)==x a possible answer, all the
		// values in the BIT, except one, have to be in the f, the other one:
		// 1: have to be in bit[f+1]
		// 2: have to be in bit[1]
		int q_r = query(100000) - query(f);
		int q_l = query(f-1);
		if (q_r + q_l == 1) {
			if (query(f+1) - query(f) == 1 || query(1) == 1)
				ans = i+1;
		}

		// Anothe possibility is when I can discart myself and set (i+1)==x
		// For this, i have to set f to the previews i;
		if (i == 0) continue;
		f = a[i-1];
		q_r = query(100000) - query(f);
		q_l = query(f-1);
		if (q_r + q_l == 1) {
			if (query(f+1) - query(f) == 1 || query(1) == 1)
				ans = i+1;
		}
	}

	// If everyone is centered in 1, the awnerr can be n
 	if ((query(100000) == query(1)))
		ans = n;

	cout << ans << endl;
}
