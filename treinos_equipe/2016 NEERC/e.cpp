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
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[i];
    int maxE = *max_element(v,v+n);
    int maxI;
    int minimo = 0;
    int maximo = 0;
    for(int i = 0; i<n; i++){
        if(v[i] == maxE) maxI = i;
    }

    /*Testa primeiro round */
    for(int i = 0; i<maxI; i++){
        minimo++;
        maximo += v[i];
    }
    if(k >= minimo && k <= maximo){
        cout << "YES" << endl;
        exit(0);
    }

    /*Testa outros rounds*/

    do{
        for(int i = 0; i<n; i++){
            if(i != maxI){
                minimo ++;
                maximo += v[i];
            }
            else{
                minimo += v[i];
                maximo += v[i];
            }
        }
        if(k >= minimo && k <= maximo){
            cout << "YES" << endl;
            exit(0);
        }
    } while(minimo <= k);
    cout << "KEK" << endl;

    
    
    
    
    
}