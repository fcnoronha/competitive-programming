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

int a[100009], ans[100005], n, memo[100005][5];

int pd(int note, int dedo){
	if (note == n+1) return 1;

	int ant = a[note-1];
	fr(i, 5){
		if (ant > a[note] && dedo <= i) continue;
		if (ant < a[note] && dedo >= i) continue;
		if (ant == a[note] && dedo == i) continue;

		if (memo[note][i] == -1) continue;

		int r = pd(note+1, i);

		if (r){
			ans[note] = i;
			return 1;
		}
		else memo[note][i] = -1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	fr(i, n)
		cin >> a[i];
	
	fr(i, 5){
		if (pd(1, i)){
			cout << i+1 << " ";
			frr(j,n-1) cout << ans[j]+1 << " ";
			cout << endl;	
			return 0;
		}
	}

	cout << "-1" << endl;
}
