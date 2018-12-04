// https://codeforces.com/contest/1088/problem/A

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
	int x;
	cin >> x;
	int a = 0, b = 0;

	frr(a, x){
		frr(b, x){
			if (a % b == 0 && a*b > x && a/b < x){
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
	cout << "-1" << endl;
}
