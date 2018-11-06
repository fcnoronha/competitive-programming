// http://www.codcad.com/problem/158

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

int n, m, order[50009];
bool visited[50009];

int main(){
	cin >> n >> m;

	vector<int> graph[n+3], list;

	fr (i, m){
		int a, b;
		cin >> a >> b;

		order[b]++;
		graph[a].pb(b);
	}

	set<int> s;

	for (int i = 0; i < n; i++){

		if (order[i] == 0){
			// list.pb(i);
			s.insert(i);
		}
	}

	

	int beg = 0;
	while (!s.empty()){
		// int t = list[beg];
		int t = *(s.begin());
		s.erase(s.begin());
		list.pb(t);
		beg++;
		// dbg(t);

		for (int u : graph[t]){
			// dbg(u);
			order[u]--;
			if (order[u] == 0){
				// list.pb(u);
				s.insert(u);
			}
		}
	}

	if (beg < n){
		printf("*\n");
		return 0;
	}

	fr (i, n){
		cout << list[i] << endl;
	}	
}
