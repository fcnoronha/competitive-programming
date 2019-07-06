//codeforces.com/contest/1185/problem/B

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

	int t;
	cin >> t;

	while (t--) {

		string s1, s2;
		cin >> s1;
		cin >> s2;

		if (s1.size() > s2.size()){
			p(NO);
			continue;
		}

		pair<char,int> freq[s2.size()+12];
		int cnt = 0;

		fr(i, s2.size()+12)
			freq[i].s = -1;

		fr(i, s2.size()) {

			if (i > 0 && s2[i] == s2[i-1]) {
				freq[cnt].s++;
				continue;
			}

			cnt++;
			freq[cnt].f = s2[i];
			freq[cnt].s = 1;
		}

		bool okok = true;
		cnt = 1;
		fr(i, s1.size()) {

			if (s1[i] != freq[cnt].f) {
				p(NO);
				okok = 0;
				break;
			}

			while (s1[i] == s1[i+1])
				freq[cnt].s--, i++;

			if (freq[cnt].s <= 0) {
				p(NO);
				okok = 0;
				break;
			}

			cnt++;
		}

		if (freq[cnt].s != -1 && okok) p(NO);
		else if (okok) p(YES);
	}
}
