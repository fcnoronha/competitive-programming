#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

typedef vector<int> vi;

vector< pair<int, string> > v;
int n;
string f;

bool busca(string s1, string s2){
	bool res = true;
	for(int j = 0; j <= (s2.length() - s1.length()); j++){
		if(s1[0] == s2[j]){
			for(int k = 1; k < s1.length(); k++){
				if(s1[k] != s2[k+j]) res = false;
			}
		}	
		if(res == true) return true;
	}
	if(res == false) return false;
}

int main(){
	cin >> n;

	fr(i, n){
		cin >> f;

		v.pb(mp(f.length(), f));
	}

	sort(v.begin(), v.end());

	fr(i, n - 1){
		if(!busca(v[i].second, v[i+1].second)){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	fr(i, v.size()){
		cout << v[i].second << endl;
	}
}

