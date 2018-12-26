// https://codeforces.com/contest/1087/problem/A

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
	fastio
	
	string s;
	cin >> s;

	vector<char> v;

	bool par = (s.length())%2 == 0 && s.length() > 1;

	int ini = 0, fim = s.length()-1;
	if (fim == ini) v.pb(s[ini]);
	while (ini < fim && par){
		v.pb(s[fim]);
		v.pb(s[ini]);

		fim--; ini++;

		if (fim == ini) v.pb(s[ini]);
	}

	while (ini < fim && !par){
		v.pb(s[ini]);
		v.pb(s[fim]);

		fim--; ini++;

		if (fim == ini) v.pb(s[ini]);
	}

	reverse(v.begin(), v.end());
	for(auto u : v) cout << u;
	cout << endl;
}
