// codcad.com/problem/62

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

int main(){
	fastio
	
	int t;
	cin >> t;

	while (t--){

		string e;
		cin >> e;

		stack<char> s;
		s.push(e[0]);

		frr(i, e.length()-1){

			char aux = '2';
			if (!s.empty()) aux = s.top();

			if (aux == '(' && e[i] == ')') s.pop();
			else if (aux == '{' && e[i] == '}') s.pop();
			else if (aux == '[' && e[i] == ']') s.pop();
			else s.push(e[i]);
		}

		if (s.size()) p(N);
		else p(S);
	}
}
