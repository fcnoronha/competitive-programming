// codeforces.com/contest/1100/problem/B

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

int main(){
	fastio
	int n, m;

	cin >> n >> m;
	vi freq(n+2, 0);
	set<int> st;
	
	int cnt = 0, x;

	fr(i, m){

		cin >> x;
		freq[x]++;
		st.insert(x);

		if (st.size() == n){
			cout << 1;
			cnt++;

			frr(i, n){
				freq[i]--;

				if (!freq[i])
					st.erase(i);
			}
		}
		else cout << 0;
	}

	cout << endl;
}
