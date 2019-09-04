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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

vi adj[90000];

bool dfs(int v, int u) {

  if (v == u) return 1;

  for (auto x : adj[v])
    if (dfs(x, u))
      return 1;

  return 0;
}

int main(){

	fastio;

  int n, m, cnt = 3;
  map<string, int> mp;
  string a, aux, b;

  cin >> n >> m;
  fr(i, n) {

    cin >> a;
    fr(j,3) cin >> aux;
    cin >> b;

    if (mp.find(a) == mp.end()) mp[a] = cnt++;
    if (mp.find(b) == mp.end()) mp[b] = cnt++;
    // dbg(mp[b]); dbg(b);
    adj[mp[b]].pb(mp[a]);
  }

  fr(i, m) {

    cin >> a;
    fr(j,3) cin >> aux, aux = "";
    cin >> b;

    if (mp.find(a) == mp.end() || mp.find(b) == mp.end()) {
      cout << "Pants on Fire\n";
      continue;
    }

    int u = mp[a];
    int v = mp[b];

    if (dfs(v, u))
      cout << "Fact\n";
    else if (dfs(u, v))
      cout << "Alternative Fact\n";
    else
      cout << "Pants on Fire\n";
  }
}

/*
4 5
Mexicans are worse than Americans
Russians are worse than Mexicans
NorthKoreans are worse than Germans
Canadians are worse than Americans
Russians are worse than Americans
Germans are worse than NorthKoreans
NorthKoreans are worse than Mexicans
NorthKoreans are worse than French
Mexicans are worse than Canadians
*/
