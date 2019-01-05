//codeforces.com/contest/1099/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl
#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int cont[209];

void prt(string s){
	fr(i, s.size()){
		if (s[i] == '#') continue;
		if (s[i] == '@'){
			fr(j, cont[i]) cout << s[i-1];
			continue;
		}
		cout << s[i];
	}
	cout << endl; 
}

int main(){
	fastio
	
	string s;
	int k;
	cin >> s >> k;

	int t = 0;
	fr(i, s.length()){
		if (s[i] != '*' && s[i] != '?')
			t++;
	}

	if (t == k){
		fr(i, s.length())
			if (s[i] == '*' || s[i] == '?')
				s[i] = '#';
		prt(s);
		return 0;
	}

	int canret = 0, canrep = 0;
	fr(i, s.length()){
		if (s[i] == '*') canrep++;
		if (s[i] == '?') canret++;
	}

	if (t > k){
		// Have to delete letters
		int delta = t-k;

		if (delta > canret+canrep){
			p(Impossible);
			return 0;
		}

		int i = 1;
		while (delta > 0){
			if (s[i] == '*' || s[i] == '?'){
				s[i] = '#';
				s[i-1] = '#';
				delta--;
			}
			i++;
		}

		while (i < s.length()){
			if (s[i] == '*' || s[i] == '?')
				s[i] = '#';
			i++;
		}

		prt(s);
		return 0;
	}

	else {
		// Have to insert letters

		int delta = k - t;

		if (canrep == 0){
			p(Impossible);
			return 0;
		}

		int i = 0;
		while (i < s.length()){
			if (s[i] == '*'){
				s[i] = '@';
				cont[i] = delta;
				break;
			}
			i++;
		}

		fr(j, s.length())
			if (s[j] == '*' || s[j] == '?')
				s[j] = '#';

		prt(s);
		return 0;
	}
}
