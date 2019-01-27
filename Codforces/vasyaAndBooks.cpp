//codeforces.com/contest/1073/problem/B

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
	
	int n;
	cin >> n;

	map<int,int> id;
	int x, cnt = 0;

	fr(i, n){
		cin >> x;
		id[x] = ++cnt;
	}

	int lst = 0;
	fr(i, n){
		cin >> x;
		x = id[x];

		if (x <= lst){
			cout << 0 << " \n"[i == n-1];
			continue;
		}

		cout << x - lst << " \n"[i == n-1];
		lst = x;
	}
}
