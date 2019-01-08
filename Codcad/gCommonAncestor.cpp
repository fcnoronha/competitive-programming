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
	
	int a, b;
	cin >> a >> b;
	fr(i, a){
		int x;
		cin >> x;
		s1.pb(x);
	}

	fr(i, b){
		int x;
		cin >> x;
		s2.pb(x);
	}

	int aux = lcs(a, b);

	cout << a-aux << " " << b-aux << endl;
}
