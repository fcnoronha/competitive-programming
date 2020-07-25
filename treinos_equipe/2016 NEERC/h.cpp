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


signed main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fastio;
    int n;
    cin >> n;
    int ans = 1;
    string stans;
    
    for(int i = 1; i<=9; i++){
        if(i > n) break;
         if(i == 1) ans *= 8;
        else ans *= 9; 
    }
    stans = to_string(ans);
    if(n >= 10){
        int dif = n - 9;
        for(int i = 0; i<dif; i++) stans += '0';
    }
    cout << stans << endl;
    
    
}