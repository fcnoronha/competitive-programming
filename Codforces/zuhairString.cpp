// codeforces.com/contest/1105/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
	fastio
	
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int ans = 0;

	for (char c = 'a'; c <= 'z'; c++){

		int aux = 0;

		int i = 0;
		while (i < n){

			if (s[i] != c){
				i++;
				continue;
			}

			int cnt = 0;
			while (i < n && cnt < k && s[i] == c) cnt++, i++;

			if (cnt == k) aux++;
		}

		ans = max(ans, aux);
	}

	cout << ans << endl;
}
