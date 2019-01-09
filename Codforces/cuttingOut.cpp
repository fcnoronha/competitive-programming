//codeforces.com/contest/1077/problem/D

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

int main(){
	fastio
		
	int n, k;
	cin >> n >> k;

	vector<pii> freq(200009);
	fr(i, 200009) freq[i] = {0, i};

	fr(i, n){
		int x;
		cin >> x;

		freq[x].f++;
	}

	sort(all(freq));
	reverse(all(freq));

	int best = 1, l = 1, r = n;

	while (l <= r){
	
		int m = (l+r)/2;
	
		int cnt = 0;
	
		for (auto u : freq)
			cnt += u.f/m;
	
		if (cnt >= k){
			best = max(best, m);
			l = m+1;
		}

		else
			r = m-1;
	}

	vi ans;

	int cnt = k;
	for (auto x : freq){
		
		if (!cnt) break;

		int aux = min(cnt, x.f/best);
		
		fr (i, aux)
			ans.pb(x.s);

		cnt -= aux;
	}

	pv(ans);
}
