//codeforces.com/contest/1185/problem/C2

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

	int n, m;
	cin >> n >> m;

	int freq[102];
	ms(freq, 0);
	vi ans;

	int t, sum = 0;
	fr(i, n) {

		cin >> t;
		sum += t;

		int rmv = 0, aux = sum;
		for (int i = 100; i > 0; --i) {
			if (aux <= m) break;

			if (i*freq[i] > (aux - m)){
				int x = ceil(double(aux-m) / (i*1.0));
				rmv += x;
				break;
			}

			aux -= i*freq[i];
			rmv += freq[i];
		}

		ans.pb(rmv);
		freq[t]++;
	}

	fr(i, n)
		cout << ans[i] << " ";
	cout << "\n";
}
