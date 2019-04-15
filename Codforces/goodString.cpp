// codeforces.com/contest/1140/problem/B

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

	while (t--){

		int n;
		cin >> n;

		string str;
		cin >> str;

		int c1 = 0, c2 = 0;

		fr(i, n){
			c1 += (str[i] == '>');
			c2 += (str[i] == '<');
		}

		if (c1 == 0 || c2 == 0 || str[0] == '>' || str[n-1] == '<'){
			cout << 0 << endl;
			continue;
		}

		c1 = 0;
		while (c1 < n && str[c1] != '>')
			c1++;

		c2 = 0;
		for (int i = n-1; i >= 0 && str[i] != '<'; i--){
			c2++;
		}

		cout << min(c1, c2) << endl;
	}
}
