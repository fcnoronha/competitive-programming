#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
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


int v[100100];

signed main(){
    fastio;
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> v[i];
    }
    v[0] = 100;
    for(int i = 1; i<=n; i++){
        v[i] += v[i-1];
    }
    int ans = 100;
    for(int i = 1; i<=n; i++){
        ans = max(ans, v[i]);
    }
    cout << ans << endl;
    
}