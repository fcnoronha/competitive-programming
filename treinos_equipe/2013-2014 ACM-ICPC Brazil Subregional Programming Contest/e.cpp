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

int mkd[100100];

signed main(){
    fastio;
    int n, R;
    cin >> n >> R;
    for(int i = 1; i<=R; i++){
        int x;
        cin >> x;
        mkd[x] = 1;
    }
    vector<int> ans;
    for(int i = 1; i<=n; i++){
        if(!mkd[i]) ans.pb(i);
    }
    sort(all(ans));
    if(ans.size() == 0){
        cout << "*" << endl;
        return 0;
    }
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
    
}