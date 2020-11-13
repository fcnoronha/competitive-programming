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
    int circulo = 0;
    set<int> pontos;
    int ac = 0;
    vector<int> numeros;
    for(int i = 0; i<n; i++){
        cin >> v[i];
        circulo += v[i];
        pontos.insert(v[i] + ac);
        numeros.pb(v[i] + ac);
        ac += v[i];
        
    }
    if(circulo % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        int x = numeros[i];
        auto it0 = pontos.find(x);
        auto it = pontos.find(x + circulo/3);
        auto it2 = pontos.find(x - circulo/3);
        if(it != pontos.end() && it2 != pontos.end()){
            pontos.erase(it0);
            pontos.erase(it);
            pontos.erase(it2);
            ans++;
        }
    }
    cout << ans << endl;

    
    

    
}