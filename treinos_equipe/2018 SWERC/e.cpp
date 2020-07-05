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

const int maxn = 1e4+5;
string nomes[maxn];
int v[maxn];
int menor[maxn];
int maior[maxn];
int minAc[maxn];
int maxAc[maxn];
int ac[maxn];

signed main(){
    fastio;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        string s; int rate;
        cin >> s;
        cin >> rate;
        nomes[i] = s;
        rate *= 100;
        v[i] = rate;
    }
    ms(menor, INF);
    ms(maior, -INF);
    cout << fixed;
    cout << setprecision(2);
    
    for(int i = 0; i<n; i++){
        minAc[i] = max(v[i] - 50, 0ll);
        maxAc[i] = min(v[i]+50-1, 10000ll);
    }
    for(int i = 1; i<=n; i++){
        minAc[i] += minAc[i-1];
        maxAc[i] += maxAc[i-1];
    }
    
    int ans = 1;
    for(int i = 0; i<n; i++){
        int flag = 0;
        int minimo = minAc[i-1] + minAc[n] - minAc[i];
                   int maximo = maxAc[i-1] + maxAc[n] - maxAc[i];
        
        for(int valor = max(v[i] - 50,0ll); valor < v[i]+50; valor++){
           
            if(10000 - valor >= minimo && 10000 - valor <= maximo){
                menor[i] = min(menor[i], valor);
                maior[i] = max(maior[i], valor);
                flag = 1;
            }
        }
        ans &= flag;
    }
    
    
    if(ans){
        for(int i = 0; i<n; i++){
            double a = menor[i] / 100.0;
            double b = maior[i] / 100.0;
            
            cout << nomes[i] << " " << a << " " << b << endl;
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    
}
