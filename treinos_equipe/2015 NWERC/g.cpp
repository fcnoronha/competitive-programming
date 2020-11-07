#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define int long long int
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int posA[200200];
int posB[200200];
int posC[200200];
int v[200200];
vector<int> blocos[1000];
signed main(){
    fastio;
    int n;
    cin >> n;
    int sizeBlock = (int) sqrt (n + .0) + 1;
    vector<pair<pii,int>> numeros;
    for(int i = 0; i<n; i++){
      int a;
      cin >> a ;
      posA[a] = i;
    }
    for(int i = 0; i<n; i++){
      int a;
      cin >> a ;
      posB[a] = i;
    }
    for(int i = 0; i<n; i++){
      int a;
      cin >> a ;
      posC[a] = i;
    }
  for(int i = 1; i<=n; i++){
      int a, b, c;
      a = posA[i];
      b = posB[i];
      c = posC[i];
      numeros.pb({{a,b},c});
  }
  int ans = 0;
  for(int i = 0; i<=n; i++) v[i] = 1e7;
  sort(numeros.begin(), numeros.end());
    for(auto x : numeros){
        int a = x.fst.fst;
        int b = x.fst.snd;
        int atual = b/sizeBlock;
        int c = x.snd;
        for(int i = 0; i<atual; i++){
            ans += upper_bound(blocos[i].begin(), blocos[i].end(), c) - blocos[i].begin();
        }
        int l = (atual)*sizeBlock;;
        for(int i = l; i<b; i++){
            if(v[i] < c) ans++;
        }
        v[b] = c;
        blocos[atual].push_back(c);
        sort(all(blocos[atual]));
    }
    cout << ans << endl;
}