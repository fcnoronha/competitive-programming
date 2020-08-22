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

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;

int matriz[20][20], mm[20][20];
int cima[20];
int esquerda[20];
int direita[20];
int baixo[20];
int n;

int backtrack(int i, int j){

    if (i > n) return 1;
    int minin = 1;
    int maxim = n;
    if(mm[i][j] != 50){
        minin = mm[i][j];
        maxim = mm[i][j];
    }
    
    for(int dig = minin; dig<=maxim; dig++ ){
    
        matriz[i][j] = dig;
        int flag = 1;

        /*Checa se o numero repete na linha*/
        for(int z = 1; z<j; z++){
            if(matriz[i][z] == dig) {
                flag = 0;
                break;
            }
        }

        /*Checa se o numero repete na coluna*/
        for(int z = 1; z<i; z++){
            if(matriz[z][j] == dig) {
                flag = 0;
                break;
            }
        }

        if(!flag) continue;
        int maior = 0;
        int visiveis = 0;
        
        if (j == n) { 
            /*Checa o numero de blocos visiveis da esquerda para direita */
            for(int z = 1; z<=j; z++){
                if(matriz[i][z] > maior){
                    visiveis++;
                    maior = matriz[i][z];
                }
            }
            if(esquerda[i] != 50 && visiveis != esquerda[i]) continue;

            maior = 0;
            visiveis = 0;
            /*Checa o numero de blocos visiveis da direita para esquerda */
            for(int z = j; z>=1; z--){
                if(matriz[i][z] > maior){
                    visiveis++;
                    maior = matriz[i][z];
                }
            }
            if(direita[i] != 50 && visiveis != direita[i]) continue;
        }
      
        maior = 0;
        visiveis = 0;
        if (i == n) {
            /*Checa o numero de blocos visiveis de cima para baixo */
            for(int z = 1; z<=i; z++){
                if(matriz[z][j] > maior){
                    visiveis++;
                    maior = matriz[z][j];
                }
            }
            if(cima[j] != 50 && visiveis != cima[j]) continue;
    
            maior = 0;
            visiveis = 0;
            /*Checa o numero de blocos visiveis de baixo para cima */
            for(int z = i; z>=1; z--){
                if(matriz[z][j] > maior){
                    visiveis++;
                    maior = matriz[z][j];
                }
            }

            if(baixo[j] != 50 && visiveis != baixo[j]) continue;
        }
        int nextI = i;
        int nextJ = j+1;
        if(nextJ > n){
            nextI = i+1;
            nextJ = 1;
        }

        if(backtrack(nextI, nextJ)) return 1;   
    }
    return 0;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){

        cin >> n;
        for(int i = 0; i<=n+1; i++){
            string s;
            cin >> s;
            for(int j = 0; j<=n+1; j++){
                char c = s[j];
                int val = 50;
                if (c != '-') val = c-'0';
                mm[i][j] = val;
                if(i == 0) cima[j] = mm[i][j];
                if(j == 0) esquerda[i] = mm[i][j];
                if(j == n+1) direita[i] = mm[i][j];
                if(i == n+1) baixo[j] = mm[i][j];
            }
        }
        if (backtrack(1,1)){
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=n; j++){
                    cout << matriz[i][j];
                }
                cout << endl;
            }
        }
        else cout << "no" << endl;
        cout << endl;
    }
}