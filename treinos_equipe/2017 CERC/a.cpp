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


string resp[1000];
int prio[1000];

set<pair<int,int>> assentos[1000];
signed main(){
    fastio;
    int n, r;
    cin >> r >> n;
    int livresEsquerdo, livresDireito;
    livresEsquerdo = livresDireito = 0;
    for(int i = 1; i<=r+3; i++){
        string s;
        cin >> s;
        resp[i] = s;
        if( i == 1 || i == r/2 + 2 || i == r+3) continue;
        for(int j = 0; j<s.size(); j++){
            char c = s[j];

            prio[i] = abs(i-1);
            prio[i] = min(prio[i], abs(i - (r/2+2)));
            prio[i] = min(prio[i], abs(i - (r+3)));

            int prioCol;
            if(j == 4 || j == 6) prioCol = 1;
            else if(j == 2 || j == 8) prioCol = 2;
            else if(j == 0 || j == 10) prioCol = 3;
            else if(j == 5) prioCol = 4;
            else prioCol = 5;
            if(c == '-') {
                if(j <= 4) livresEsquerdo++;
                else if(j >= 6)livresDireito++;
                assentos[i].insert({prioCol, j });
            }
            
        }
    }
    
    for(int i = 0; i<n; i++){
        
        int linha;
        if(assentos[2].size() && assentos[r/2 + 3].size()) {
            if(assentos[2].size() >= assentos[r/2+3].size()) linha = 2;
            else linha = r/2+3;
        }
        else if(assentos[2].size()){
            linha = 2;
        }
        else if(assentos[r/2 + 3].size()) {
            linha = r/2+3;

        }
        else{
            linha = 1;
            for(int j = 1; j<=r+3; j++){
                if(assentos[j].size() > assentos[linha].size() ) linha = j;
            }
            int valorMaximo = assentos[linha].size();

            for(int j = 1; j<=r+3; j++){
                if(assentos[j].size() == valorMaximo && prio[j] < prio[linha]){
                    linha = j;
                }
            }

        }
        pair<int,int> primeiro = *assentos[linha].begin();
        assentos[linha].erase(assentos[linha].begin());
        int prioPrimeiro = primeiro.fst;
        int colunaPrimeiro = primeiro.snd;
        int prioSegundo = -1;
        pair<int,int> segundo;
        if(assentos[linha].size() >= 1){
            segundo = *assentos[linha].begin();
            prioSegundo = segundo.fst;
        }
        if(prioSegundo == prioPrimeiro){
           
            assentos[linha].erase(assentos[linha].begin());
            
            int colunaSegundo = segundo.snd;
            /* Primeiro: esquerdo, segundo:direito*/
            if (colunaPrimeiro <= 4 && colunaSegundo > 4){
                //Escolhe primeiro
                if(livresEsquerdo >= livresDireito){
                    livresEsquerdo--;
                    resp[linha][colunaPrimeiro] = 'a' + i;
                    assentos[linha].insert(segundo);
                }
                //Escolhe segundo
                else{
                    livresDireito--;
                    resp[linha][colunaSegundo] = 'a' + i;
                    assentos[linha].insert(primeiro);
                }
            }
            /* Primeiro: direito, segundo:esquerdo*/
            else{
                //Escolhe segundo
                if(livresEsquerdo >= livresDireito){
                    livresEsquerdo--;
                    resp[linha][colunaSegundo] = 'a' + i;
                    assentos[linha].insert(primeiro);
                }
                //Escolhe primeiro
                else{
                    livresDireito--;
                    resp[linha][colunaPrimeiro] = 'a' + i;
                    assentos[linha].insert(segundo);
                }
            }
        }
        else{
            if(colunaPrimeiro <= 4){
                livresEsquerdo--;
            }
            else if (colunaPrimeiro >= 6){
                livresDireito--;
            }
            resp[linha][colunaPrimeiro] = 'a' + i;
        }
    }
    for(int i = 1; i<=r+3; i++){
        cout << resp[i] << endl;
    }
  
}

