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

#define maxg 1009
#define maxb 1209

bool dp[maxg][maxb];
int ant[maxg][maxb];
vi vg;
vi vb;
vector<string> vs;

int main(){

	int m, u, d;
	double a, b;
	cin >> a >> b >> d;

	a += 0.005;
	b += 0.005;
	m = a*100;
	u = b*60;

	fr(i, d){

		string beb;
		cin >> beb;

		int pct;
		cin >> pct;

		string f;
		cin >> f;

		double cst;
		cin >> cst;
		cst += 0.005;

		vs.pb(beb);

		vb.pb(pct*60/(f[2]-'0'));
		vg.pb(cst*100);
	}

	dp[0][0] = 1;

	fr(i, d){

		if (!vb[i] && !vg[i])
			continue;

		for (int g = m; g >= 0; g--){
			for (int b = u; b >= 0; b--){

				if (dp[g][b]){

					for (int k = 1;; k++){
						int gk = vg[i]*k + g;
						int bk = vb[i]*k + b;

						if (gk > m || bk > u || dp[gk][bk])
							break;

						dp[gk][bk] = 1;
						ant[gk][bk] = i;
					}
				}
			}
		}
	}

	vi freq(d, 0);

	if (!dp[m][u]){
		printf("IMPOSSIBLE\n");
		return 0;
	}

	int aux = ant[m][u];

	while (m != 0 || u != 0){

		freq[aux]++;
		m -= vg[aux];
		u -= vb[aux];

		aux = ant[m][u];
	}

	fr(i, d)
		if (freq[i] > 0)
			cout << vs[i] << " " << freq[i] << endl;


}
