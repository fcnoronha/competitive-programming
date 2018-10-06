// http://codeforces.com/contest/1059/problem/B

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(long long int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll n, m;

int grid[1001][1001];	

int main(){
	cin >> n >> m;

	fr (i,n){
		string x;
		cin >> x;
		fr (j, m){			
			if (x[j] == '.') grid[i][j] = -1;
			if (x[j] == '#') grid[i][j] = 0;
		}
	}


	fr (i,n-2){
		fr (j,m-2){
			if (grid[i][j] == -1) continue;
			if (grid[i+1][j] == -1) continue;
			if (grid[i+2][j] == -1) continue;
			if (grid[i][j+1] == -1) continue;
			if (grid[i+2][j+1] == -1) continue;
			if (grid[i+1][j+2] == -1) continue;
			if (grid[i+2][j+2] == -1) continue;
			if (grid[i][j+2] == -1) continue;

			grid[i][j] = 1;
			grid[i+1][j] = 1;
			grid[i+2][j] = 1;
			grid[i][j+1] = 1;
			grid[i+2][j+1] = 1;
			grid[i+1][j+2] = 1;
			grid[i+2][j+2] = 1;
			grid[i][j+2] = 1;
		}
	}

	fr (i,n){
		fr (j, m){
			if (grid[i][j] == 0){
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
}
