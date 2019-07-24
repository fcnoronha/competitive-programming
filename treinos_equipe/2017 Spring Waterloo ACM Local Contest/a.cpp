//codeforces.com/gym/101431/problem/A

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

string line[5][5];
string outp[5];

int main(){
	fr(i, 5){
		outp[i] = "";
		fr(j, 5) line[i][j] = "";
	}
	fastio
	int n;
	fr(i, 5) line[i][0] = "***";
	line[2][1] = line[4][1] = line[2][2] = line[2][3] = line[4][3] = "*..";
	line[0][1] =  line[1][1] = line[0][3] = line[0][4] = line[1][3] = "*.*";
	line[0][2] = line[1][2] = line[4][2] = line[2][4] = line[1][4] = line[4][4] = line[3][4] = "***";
	for(int i = 1; i <=3; i++) line[3][i] = "*.*";
	cin >> n;
	fr(i ,n){
		char c; cin >> c;
		fr(i, 5) outp[i] += line[c - 'A'][i];
	}
	fr(i, 5){
		cout << outp[i] << endl;
	}		
}
