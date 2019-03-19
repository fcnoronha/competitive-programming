#include "bits/stdc++.h"
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

#define gnl cout << endl
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;

int grid[550][550];
int n,m; 
int mx1[550][550],mx2[550][550];
int mx3[550][550],mx4[550][550];


void go(){

	cin >> n >> m;
	

	frr(i,n)
		frr(j,m)
			cin >>	grid[i][j];

	ms(mx1,0);
	ms(mx2,0);
	ms(mx3,0);
	ms(mx4,0);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			mx1[i][j]=max({ grid[i][j], mx1[i-1][j], mx1[i][j-1]} );
		
	for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--)
			mx2[i][j]=max({ grid[i][j], mx2[i][j+1],mx2[i-1][j] });

	for(int i=n;i>0;i--)
		for(int j=1;j<=m;j++)
			mx3[i][j]=max({ grid[i][j], mx3[i][j-1], mx3[i+1][j] });

	for(int i=n;i>0;i--)
		for(int j=m;j>0;j--)
			mx4[i][j]=max({ grid[i][j], mx4[i][j+1],mx4[i+1][j]  });

	int ans = INF;
	
	for(int i=2;i<n;i++)
		for(int j=2;j<m;j++){
			int mx= max({mx1[i-1][j-1],mx2[i-1][j+1],mx3[i+1][j-1],mx4[i+1][j+1]});
			int mn= min({mx1[i-1][j-1],mx2[i-1][j+1],mx3[i+1][j-1],mx4[i+1][j+1]});
			ans=min(ans,abs(mx-mn));
		}	

	cout << ans << endl;


}

int main(){

	fastio;

	int t; cin >> t;
	while(t--)	go();

	
}