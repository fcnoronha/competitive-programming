#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
    
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = LLONG_MAX;


int v[500500];
signed main(){
    fastio;
    int n;
    cin >> n;
      for(int i = 0; i<n; i++) cin >> v[i];
    set<int> atual;
    set<int> ans;
    atual.insert(v[n-1]);
    ans.insert(v[n-1]);
    for(int i = n-2; i>=0; i--){
        set<int> novoAtual;
        for(auto y : atual){
            int z = __gcd(y, v[i]);
            novoAtual.insert(z);
            ans.insert(z);
        }
        novoAtual.insert(v[i]);
        ans.insert(v[i]);
        atual = novoAtual;
    }
    cout << ans.size() << endl;
}
