//codeforces.com/contest/1110/problem/B

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

int main(){
	fastio
	
	int n, m, k;
	cin >> n >> m >> k;

	int b[n];
	fr(i, n) cin >> b[i];

	if (k >= n){
		cout << n << endl;
		return 0;
	}

	int tape[n-1];
	ll tcost = b[n-1] - b[0] + 1;
	fr(i, n-1)
		tape[i] = b[i+1] - b[i] - 1;
	
	sort(tape, tape+n-1);
	reverse(tape, tape+n-1);

	fr(i, min(k-1, n-2)) tcost -= (ll)tape[i];

	cout << tcost << endl;
}
