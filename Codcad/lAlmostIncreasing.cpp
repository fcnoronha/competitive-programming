// codcad.com/lesson/40

// codcad.com/problem/68

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

int dp[1009][1009];
vi s1, s2;

int lcs(int a, int b){

	for (int i = 0; i <= a; i++){
		for (int j = 0; j <= b; j++){

			if (!i || !j) dp[i][j] = 0;

			else if (s1[i-1] == s2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];

			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[a][b];
}

int main(){
	fastio
	
	int n;
	cin >> n;

	vi aux;

	fr(i, n){
		int x;
		cin >> x;
		s1.pb(x);
		aux.pb(x);
	}

	map<int, int> m;
	sort(aux.begin(), aux.end());
	int cnt = 1;
	fr(i, n){
		if (i > 0 && aux[i] == aux[i-1]) continue;
		m[aux[i]] = cnt++;
	}

	fr(i, n) s1[i] = m[s1[i]];

	vi rep(cnt+3, 0);
	fr(i, n) rep[s1[i]]++;

	frr(i, cnt+1) fr(j, rep[i]) s2.pb(i);

	cout << lcs(s1.size(), s2.size()) << endl;
}
