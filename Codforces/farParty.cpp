// https://codeforces.com/contest/1081/problem/B

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
typedef vector<pii> vi;

int main(){
	int n;
	cin >> n;

	vector<int> mem;
	vi v(n+5, {0,0});
	fr(i, n){
		int a;
		cin >> a;
		mem.pb(a);

		a = n-a;
		v[a].f++;
	}

	bool taoquei = false;

	fr(i, n+2)
		if (v[i].f > 0 && v[i].f%i != 0)
			taoquei = true;

	if (taoquei){
		cout << "Impossible" << endl;
		return 0;
	}


	cout << "Possible" << endl;
	int t = 1;
	fr(i, n+2){
		if(v[i].f > 0){
			v[i].f = t;
			v[i].s = i;
			t++;
		}
	}

	for (auto i : mem){

		int aux = n-i;

		if (v[aux].s == 0){
			v[aux].s = aux;
			v[aux].f = t;
			t++;
		}

		v[aux].s--;

		cout << v[aux].f << " ";
	}
	cout << endl;
}
