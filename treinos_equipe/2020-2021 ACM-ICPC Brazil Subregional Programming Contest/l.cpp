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


int mapa[30];
set<int> ans[50][50];
char matriz[50][50];
string letras[100];
void limpaMapa(int z){
    for(int v = 0; v<30; v++){
                    mapa[v] = 0;
    }
    for(int j = 0; j<letras[z].size(); j++){
        char c = letras[z][j];
        int pos = c-'A';
        mapa[pos]++;
    }
}
int checa(int linha, int coluna, int z){
    int c = matriz[linha][coluna];
    int pos = c - 'A';
    if(mapa[pos] == 0) return 0;
    mapa[pos]--;
    return 1;
}
signed main(){
    fastio;
    int l,c;
    cin >> l >> c;
    
    for(int i = 0; i<l; i++){
        for(int j = 0; j<c; j++){
            cin >> matriz[i][j];
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> letras[i];
    }
    for(int z = 0; z<n; z++){
        for(int i = 0; i<l; i++){
            for(int j = 0; j<c; j++){
                    
                    /*3*/
                    limpaMapa(z);
                    int flag = 1;
                    int linha = i;
                    int coluna = j;
                    int cnt = letras[z].size();
                    while(coluna < c && cnt){
                        flag &= checa(linha,coluna,z);
                        cnt--;
                        coluna++;
                    }
                    if(flag && cnt == 0){
                        linha = i;
                        coluna = j;
                        cnt = letras[z].size();
                        while(coluna < c && cnt){
                            ans[linha][coluna].insert(z);
                            coluna++;
                            cnt--;
                        }
                    }
                    /*4*/
                    limpaMapa(z);
                    flag = 1;
                    linha = i;
                    coluna = j;
                    cnt = letras[z].size();
                    while(linha < l && coluna < c && cnt){
                        flag &= checa(linha,coluna,z);
                        coluna++;
                        linha++;
                        cnt--;
                    }
                    if(flag && cnt == 0){
                        linha = i;
                        coluna = j;
                        cnt = letras[z].size();
                        while(linha < l && coluna < c && cnt){
                            ans[linha][coluna].insert(z);
                            linha++;
                            coluna++;
                            cnt--;
                        }
                    }
                    /*5*/
                    limpaMapa(z);
                    flag = 1;
                    linha = i;
                    coluna = j;
                    cnt = letras[z].size();
                    while(linha < l && cnt){
                        flag &= checa(linha,coluna,z);
                        linha++;
                        cnt--;
                    }
                    if(flag && cnt == 0){
                        linha = i;
                        coluna = j;
                        cnt = letras[z].size();
                        while(linha < l && cnt){
                            ans[linha][coluna].insert(z);
                            linha++;
                            cnt--;
                        }
                    }

                    /*6*/
                    limpaMapa(z);
                    flag = 1;
                    linha = i;
                    coluna = j;
                    cnt = letras[z].size();
                    while(linha < l && coluna >= 0 && cnt){
                        flag &= checa(linha,coluna,z);
                        linha++;
                        coluna--;
                        cnt--;
                    }
                    if(flag && cnt == 0){
                        linha = i;
                        coluna = j;
                        cnt = letras[z].size();
                        while(linha < l && coluna >= 0 && cnt){
                            ans[linha][coluna].insert(z);
                            linha++;
                            coluna--;
                            cnt--;
                        }
                    }
                }
        }
    }
    int resposta = 0;
    for(int i = 0; i<l; i++){
        for(int j = 0; j<c; j++){
            
            if(ans[i][j].size() > 1) {
                resposta++;
            }
        }
    }
    cout << resposta<<endl;
    
}