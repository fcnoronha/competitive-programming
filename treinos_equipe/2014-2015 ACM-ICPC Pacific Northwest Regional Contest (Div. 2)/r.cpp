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
const int INF = 0x3f3f3f3f;

int pd[100][50];

int solve(int n, int x){
    if(pd[n][x] != -1) return pd[n][x];
    dbg(n);
    dbg(x);
    return pd[n][x] = solve(n,x+1) + solve(n-1, x);
}

int invalid(string &s){
    for(int i = 1; i<s.size(); i++){
        if(s[i] < s[i-1]) return 1;
    }
    return 0;
}
signed main(){
    fastio;
    int t;
    cin >> t;
    pd[0][9] = 1;
    for(int i = 1; i<100; i++){
        for(int j = 9; j>=0; j--){
            pd[i][j] = pd[i][j+1] + pd[i-1][j];
        }
    }
    while(t--){
        string s;
        cin >> s;
        if(invalid(s)) cout << -1 << endl;
        else{
            int n = s.size();
            int last = 0;
            int ans = 0;
            for(int i = 0; i<n; i++){
                int dig = s[i]-'0';
                for(; last<dig; last++) ans += pd[n-i][last];
               
            }   
            cout << ans << endl;
        }
    }
}
