#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define pb push_back
#define fst first
#define snd second

#define all(x) x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;

const int INF =  0x3f3f3f3f;

int vis[100100];
vi adj[100100];
int n,k;
int pd[100100];
int pai[100100];
int hgt[100100];
int used[100100];

void dfs(int v){

	vis[v]=1;
	pd[v]=v;
	
	for(auto x : adj[v]){

		if(vis[x])
			continue;

		hgt[x]=1+hgt[v];
		pai[x]=v;

		dfs(x);

		if(hgt[pd[x]]>hgt[pd[v]])
			pd[v]=pd[x];

	}

}

int main(){

	fastio;

	cin >> n >> k;

	for(int i=2;i<=n;i++){
		int x; cin >> x;
		adj[i].pb(x);
		adj[x].pb(i);
	}

	hgt[1]=1;
	dfs(1);

	vii best;

	for(int i=1;i<=n;i++){
		best.push_back(make_pair(hgt[pd[i]]-hgt[i]+1, i));
	}

	sort(all(best));
	reverse(all(best));

	int cnt = 0;

	//for(int i=1;i<=n;i++)
		//cout << i << " - " << pd[i] << endl;


	for(auto cara : best){
		int amt = cara.fst;
		int quem = cara.snd;
		if(used[quem] || !k)
			continue;
		k--;
		cnt+=amt;
		for(int i = pd[quem];!used[i] && i!=0;i=pai[i]){
			used[i]=1;
		}
	}

	cout << cnt << endl;

}