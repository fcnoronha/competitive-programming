// https://codeforces.com/contest/1084/problem/C

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

const int mod = 1000000007;

int main(){
	string s;
	cin >> s;
	vi v;

	ll aux = 0;
	fr(i, s.length()){
		if (s[i] == 'a') aux++;
		else if (s[i] == 'b') v.pb(aux), aux = 0;
	}

	if (aux > 0) v.pb(aux);

	if (v.size() == 0){
		cout << 0 << endl;
		return 0;
	}

	ll ans = v[0]+1;
	frr(i, v.size()-1)
		ans = (ans * (v[i]+1))%mod;

	ans--;
	cout << ans << endl;
}
