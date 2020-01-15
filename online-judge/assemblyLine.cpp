// icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2962

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

	int k;
	bool opa = false;

	while (cin >> k && k) {

		if (opa) cout << endl;
		opa = true;

		char type[k], trs;

		fr (i, k)
			cin >> type[i];

		char result[k][k];
		int times[k][k];

		fr (i, k)
			fr (j, k)
				cin >> times[i][j] >> trs >> result[i][j];

		int n;
		cin >> n;

		fr(i, n) {

			string s;
			cin >> s;

			int ss = s.size();

			// (i, j, k) states
			int dp[ss][ss][k];

			// Initial state
			fr(i, ss)
				fr(l, k){
					if (type[l] == s[i])
						dp[i][i][l] = 0;
					else
						dp[i][i][l] = INT_MAX;
				}

			int wdw = 2;

			while (wdw <= ss) {

				fr(i, ss-wdw+1) {

					fr(act_l, k) {

						int mn = INT_MAX;

						fr(l1, k) {
							fr(l2, k) {

								if (type[act_l] != result[l1][l2])
									continue;

								for (int m = i; m < i+wdw-1; m++)
									if (dp[i][m][l1] != INT_MAX && dp[m+1][i+wdw-1][l2] != INT_MAX)
										mn = min(mn, dp[i][m][l1] + dp[m+1][i+wdw-1][l2] + times[l1][l2]);
							}
						}

						dp[i][i+wdw-1][act_l] = mn;
					}
				}

				++wdw;
			}

			int mn = INT_MAX;
			char ans;
			fr (i, k) {
				if (dp[0][ss-1][i] < mn) {
					mn = dp[0][ss-1][i];
					ans = type[i];
				}
			}
			cout << mn << "-" << ans << endl;
		}
	}
}
