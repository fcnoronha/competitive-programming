//codeforces.com/contest/1155/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << x << endl
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

	int n;
	cin >> n;

	string s;
	cin >> s;

	int cnt1 = (n-11)/2;
	int cnt2 = cnt1;

	fr(i, n) {

		if (s[i] == '8') {

			if (cnt1) {
				cnt1--;
				continue;
			}

			p("YES");
			return 0;
		}

		if (cnt2) {
			cnt2--;
			continue;
		}

		p("NO");
		return 0;
	}
}
