// codeforces.com/contest/1076/problem/A

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
	int n;
	cin >> n;

	string s;
	cin >> s;

	char l = 'a';
	int k = 0;
	while (k < n){
		if (s[k] <= s[k+1])
			k++;
		else
			break;
	}
	if (k == n) k--;


	fr(i, n)
		if (k != i)
			cout << s[i];
	
	cout << endl;
}	
