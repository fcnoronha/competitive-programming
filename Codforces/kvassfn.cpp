// https://codeforces.com/contest/1084/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	ll n, s, mn = LLONG_MAX, ans = 0;
	cin >> n >> s;

	ll v[n];
	fr(i, n){
		cin >> v[i];
		mn = min(mn, v[i]);
	}

	fr(i, n){
		ans += v[i] - mn;
	}

	if (ans >= s){
		cout << mn << endl;
		return 0;
	}

	s -= ans;
	ans = 0;

	ans = ceil(s/(n*1.0));
	if (ans <= mn) cout << mn-ans << endl;
	else cout << "-1" << endl;
}
