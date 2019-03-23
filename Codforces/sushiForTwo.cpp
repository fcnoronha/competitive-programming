// codeforces.com/contest/1138/problem/A

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

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
typedef long double ld;

int main(){
	fastio

	int n, x, ant;
	cin >> n >> ant;

	stack<int> q;
	q.push(1);

	fr(i, n-1){
		cin >> x;

		if (x == ant){
			int aux = q.top();
			q.pop();
			q.push(aux+1);
		}

		else {
			ant = x;
			q.push(1);
		}
	}

	int ans = 0;
	ant = q.top();
	q.pop();

	while (!q.empty()){

		ans = max(ans, min(ant, q.top()));

		ant = q.top();
		q.pop();
	}

	cout << ans*2 << endl;
}
