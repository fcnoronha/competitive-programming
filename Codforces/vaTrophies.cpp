// https://codeforces.com/contest/1082/problem/B

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
	string s;
	int n;
	vector<int> v;
	int c = 1;

	cin >> n >> s;

	frr(i, n){
		if (i == n) v.pb(c);
		else if (s[i] == s[i-1]) c++;
		else{
			v.pb(c);
			c = 1;
		}
	}
	v.pb(0); v.pb(0); v.pb(0); v.pb(0);


	int ans = 0;
	if (s[0] == 'G'){

		int cs = 0;
		for (int i = 1; i < v.size()-4; i+=2)
			cs += v[i];
		
		for (int i = 0; i < v.size()-4; i+=2){
			if (v[i+1] <= 1)
				ans = max(ans, v[i]+v[i+2]+1);
			else if (v[i+1] > 1)
				ans = max(ans, v[i]+1);
		}

		if (ans > n-cs)
			ans--;
	}

	if (s[0] == 'S'){

		int cs = 0;
		for (int i = 0; i < v.size()-4; i+=2)
			cs += v[i];
		
		for (int i = 1; i < v.size()-4; i+=2){
			if (v[i+1] <= 1)
				ans = max(ans, v[i]+v[i+2]+1);

			else if (v[i+1] > 1)
				ans = max(ans, v[i]+1);
		}

		if (ans > n-cs)
			ans--;
	}

	cout << ans << endl;
}
