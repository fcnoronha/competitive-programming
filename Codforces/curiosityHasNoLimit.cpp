//codeforces.com/contest/1072/problem/B

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

int memo[100009][5][5], a[100009], b[100009], n;
// 1 - YES / 0 - Nothing / -1 - NO

int dp(int ind, int numn, int numa){

	if (ind == n) return 1; 
	if (memo[ind][numn][numa] == -1) return -1; 
	if (((numn|numa) != a[ind-1]) || ((numn&numa) != b[ind-1]))
		return -1;

	fr(i, 4){

		if (memo[ind+1][i][numn] == -1) continue;

		memo[ind+1][i][numn] = dp(ind+1, i, numn);
		if (memo[ind+1][i][numn] == 1) return 1;		
	}

	return -1;
}

int main(){
	fastio
	
	cin >> n;
	fr(i, n-1) cin >> a[i];
	fr(i, n-1) cin >> b[i];
	fr(i, n+5) fr(j, 4) fr(h, 4) memo[i][j][h] = 0;

	fr(i, 4){

		fr(j, 4){
			memo[1][j][i] = 0;
			memo[1][j][i] = dp(1, j, i);
			// dbg(memo[1][j]);
			if (memo[1][j][i] == 1){

				p(YES);

				cout << i << " ";

				for (int p = 1; p < n; p++){
					fr(q, 4) fr(k, 4)
						if (memo[p][q][k] == 1){
							cout << q << " \n"[p == n-1];
							break;
						}
				}

				return 0;
			}
		}
	}

	p(NO);
}
