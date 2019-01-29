// codeforces.com/problemset/problem/1034/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

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

const int MAXN = 1e7+5e6+10;

int freq[MAXN];
int prs[MAXN];

int main(){
	fastio
		
	for (int i = 2; i < MAXN; i++){

		if (prs[i]) continue;

		for (int j = i; j < MAXN; j += i)
			if (!prs[j])
				prs[j] = i;
	}

	int n;
	cin >> n;

	int a[n];
	fr(i, n) cin >> a[i];

	int g = a[0];
	frr(i, n-1) g = __gcd(g, a[i]);
	fr(i, n) a[i] /= g;

	//map<int, int> freq;
	fr(i, n){

		int aux = a[i];
		while (aux != 1){

			int d = prs[aux];
			freq[d]++;

			while (aux%d == 0)
				aux /= d;
		}
	}

	int ans = INT_MAX;
	fr(i, 15000009) ans = min(ans, n - freq[i]);

	frr(i, n-1){
		if (a[i] != a[i-1] || a[i] > 1) break;
		if (i == n-1) ans = -1;
	}

	if (ans == n || ans == INT_MAX) ans = -1;

	cout << ans << endl;
}
