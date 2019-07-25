#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
 
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x);
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1000000007;
 
int arr[55];
int memo[51][51][51][51];
 
 
int pd(int left, int right, int i, int j, int vaca){
	if(i >= j) return 0; 

	int& pdm = memo[left][right][i][j];
 
	if(pdm != -1) return pdm;
	
	pdm = 0;

	if(right+arr[j] == left+arr[i]) {
		pdm++;
		pdm += pd(0, 0, i+1, j-1, 0);
		pdm %= MOD; 
	}

	if (vaca <= 1) pdm += pd(left+arr[i], right, i+1, j, 1);
	pdm %= MOD;
	pdm += pd(left, right + arr[j], i, j-1, 2);

	return pdm%MOD;
}
 
 
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int m = s.size();
		fr(i, m){
			arr[i] = (int) (s[i] - '0');
		}
 
		fr(i, m+1){
			fr(j, m+1){
				fr(k, m+1){
					fr(l, m+1) memo[i][j][k][l] = -1;
				}
			}
		}
 
		cout << pd(0, 0, 0, m-1, 0) + 1 << endl;
	}
}
