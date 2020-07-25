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

const int maxn = 2e7;
bool mkd[maxn];


signed main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    fastio;
    int n;
    cin >> n;
    for(int i = 2; i < maxn; i++) mkd[i] = 1;
    for(int i = 2; i*i <= n; i++){
        if(mkd[i]){
            for(int j = i *i; j<=n; j +=i) mkd[j] = 0;
        }
    }
    int divisores = 0;
    for(int i = 2; i<=n; i++){
        if(mkd[i] && n % i == 0){
            divisores++;
            n  = n/i;
        }
    }
    if(divisores == 3){
        cout << "YES" << endl;
        
    }
    else cout << "NO" << endl;
    
    
}