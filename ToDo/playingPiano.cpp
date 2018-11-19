// http://codeforces.com/contest/1079/problem/C

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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	int n;
	cin >> n;

	vector<int> v(n+3, 0);
	vector<int> lazy(n+3, 0);
	vector<int> a(n+3, 0);

	int ant, x;
	cin >> ant;
	v[0] = 1;

	frr(i, n-1){
		cin >> x;

		if (ant > x){
			v[i] += v[i-1] - 1;

			if (v[i] < 1){
				v[i] = 1;
				lazy[i-1] += 1;
			}
		}

		else if (ant < x){
			v[i] += v[i-1] + 1;
			
			if (v[i] > 5){
				v[i] = 5;
				lazy[i-1] += -1;
			}
		}

		a[i] = x;
		ant = x;
	}

	for (int i = n; i >= 0; i--){
			
		lazy[i] += lazy[i+1];
		if (v[i] != 0)
			v[i] += lazy[i];
		
	}

	vector<pii> aux;

	for (int i = 0; i < n-1; i++){
		if (v[i] == 0 && v[n+1] > 0){
			if (a[i] > a[i+1])
				v[i] = v[i+1] + 1;

			if (a[i] < a[i+1])
				v[i] = v[i+1] - 1;

			aux.pb({i, v[i]});
		}
	}

	for (int i = 0; i < n-1; i++){
		if (v[i] == 0){

			pii oi = aux.back();
			aux.pop_back();

			if (a[i] > a[i+1])
				v[i] = v[i+1] + 1;

			if (a[i] < a[i+1])
				v[i] = v[i+1] - 1;

			aux.pb({i, v[i]});
		}
	}

	fr(i, n){
		if (v[i] < 1 || v[i] > 5){
			printf("-1\n");
			// return 0;
		}
	}

	fr(i, n){
		cout << v[i] << " ";
	}

	cout << endl;
}
