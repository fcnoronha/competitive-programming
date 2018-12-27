// https://codeforces.com/contest/1095/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl



#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	fastio
	
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<char> ans;

	int k = 0;
	for (int i = 0; i < n; i++){
		ans.pb(s[i]);
		i += k++;
	}

	for (auto u : ans) cout << u;
	cout << endl;
}
