#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
    
#define ms(x,i)    memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
    
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;

int v[100100];

signed main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fastio;
    int n, m;

    cin >> n >> m;
    vector<pii> ans;
    if(n%2 && m%2){
        for(int i = 1; i<m-1; i+=2){
            ans.pb({n-1,i});
        }
        for(int i = 1; i<n; i+=2){
            ans.pb({i,m-1});
        }
        for(int i = 1; i<n; i+=2){
            for(int j = 1; j<m-2; j++){
                ans.pb({i,j});
            }
        }
        for(int i = 1; i<n-1; i++){
            ans.pb({i,m-2});
        }
    }
    else if(n%2 == 0 && m%2){
        for(int i = 1; i<n; i+=2){
            ans.pb({i,m-1});
        }
        for(int i =1; i<=n; i+=2){
            for(int j = 1; j<m-2; j++){
                ans.pb({i,j});
            }
        }
        for(int i = 1; i<n; i++){
            ans.pb({i,m-2});
        }
    }
    else if(n%2 == 0 && m%2 == 0){
        for(int i =1; i<=n; i+=2){
            for(int j =1; j<m-1; j++){
                ans.pb({i,j});
            }
        }
        for(int i = 1; i<n; i++){
            ans.pb({i,m-1});
        }
    }
    else if(n%2 && m%2 == 0){
        for(int i = 1; i<m; i+=2){
            ans.pb({n-1, i});
        }
        for(int i = 1; i<n; i+=2){
            for(int j = 1; j<m-1; j++){
                ans.pb({i,j});
            }
        }
        for(int i = 1; i<n-1; i++){
            ans.pb({i,m-1});
        }
    }
    if(n == 1 || m == 1){
        cout << 0 << endl;
        exit(0);
    }
    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x.fst << " " << x.snd << endl;
    }

    
    
    
    
    
}