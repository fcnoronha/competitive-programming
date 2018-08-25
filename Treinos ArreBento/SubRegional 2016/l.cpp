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
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int m[220][220];
int vis[220][220];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int h,l;
	
bool ingrid(int a, int b){
	if(a<0 || a>=h)
		return false;
	if(b<0 || b>=l)
		return false;
	return true;
}

int dfs(int x, int y){

	vis[x][y]=1;

	int ans = 1;

	fr(l,4){
		int fx = x+dx[l];
		int fy = y+dy[l];

		if(!ingrid(fx,fy))
			continue;
		if(vis[fx][fy])
			continue;
		if(m[fx][fy]!=m[x][y])
			continue;
		ans+=dfs(fx,fy);
	}

	return ans;

}

int main(){

	cin >> h >> l;

	fr(i,h)
		fr(j,l)
			cin >> m[i][j];

	int ans = INF;

	fr(i,h){
		fr(j,l){
			if(vis[i][j])	continue;
			int aux = dfs(i,j);
			if(aux<ans)
				ans = aux;
		}
	}

	cout << ans << endl;
	
}