// http://www.codcad.com/problem/48

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n, ini, fim, hi, hf, cont;
vector<pair<int,int> > v;

int main(){
	cin >> n;

	fr(i, n){
		cin >> ini >> fim;
		v.pb({fim, ini});
	}

	sort(v.begin(), v.end());

	fr(i, n){
		if(v[i].second >= hf){
			hf = v[i].first;
			cont++;
		}
	}

	cout << cont << endl;
}

