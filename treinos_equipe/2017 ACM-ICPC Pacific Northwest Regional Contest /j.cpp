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

int pd[100][100];
char matriz[100][100];
int n, m;
int merda(int coluna, int bloco){
    for(int i = bloco-1; i>=0; i--){
        if(matriz[i][coluna] == 'R') return 1;
    }
    for(int i = bloco; i<=n; i++){
        if(matriz[i][coluna] == 'B') return 1;
    }
    return 0;


}


signed main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> matriz[i][j];
        }
    }
    for(int i = 0; i<=n; i++){
        pd[0][i] = !merda(0,i);
    }

    for(int i = 1; i<m; i++){
        for(int j = 0; j<=n; j++){
            if(merda(i,j)) continue;
            int soma = 0;
            for(int z = j; z<=n; z++){
                soma += pd[i-1][z];
            }
            pd[i][j] = soma;
        }
    }
    int ans = 0;

    for(int i = 0; i<=n; i++) {
        ans += pd[m-1][i];
    }
    cout << ans << endl;
    
}
