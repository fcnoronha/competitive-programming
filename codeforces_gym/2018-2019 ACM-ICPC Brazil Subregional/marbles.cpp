// codeforces.com/gym/101908/problem/B

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

#define MAXN 109

int g[MAXN][MAXN];
bool aux[MAXN*MAXN];

int main(){
	fastio
	
	// Precalc
	frr(i, 100){
		frr(j, 100){

			if (i == j) continue;
			ms(aux, false);

			frr(k, 100){
				if (i-k > 0 && i-k != j) aux[g[i-k][j]] = 1;
				if (j-k > 0 && j-k != i) aux[g[i][j-k]] = 1;
				if (j-k > 0 && i-k > 0) aux[g[i-k][j-k]] = 1;
			}

			fr(k, MAXN*MAXN){
				if (!aux[k]){
					g[i][j] = k;
					break;
				}
			}
		}
	}

	int n;
	cin >> n;

	int x, y, ans = 0, f = 0;
	while (n--){
		cin >> x >> y;
		if (x == y) f = 1;
		ans ^= g[x][y];
	}

	if (f || ans) p(Y);
	else p(N);
}
