    #include "bits/stdc++.h"
    using namespace std;
    #define pb push_back
    #define mp make_pair
    #define fst first
    #define snd second
     
    #define fr(i,n)	for(int i=0;i<n;i++)
    #define frr(i,n)	for(int i=1;i<=n;i++)
     
    #define ms(x,i)	memset(x,i,sizeof(x))
    #define dbg(x) cout << #x << " = " << x << endl
    #define all(x) x.begin(),x.end()
     
    #define gnl cout << endl
    #define olar cout << "olar" << endl
    #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     
     
    typedef long long int ll;
    typedef pair<int,int> pii;
    typedef vector<int> vi;
    typedef vector<pii> vii;
    typedef pair<ll,ll> pll;
     
    const int INF = 0x3f3f3f3f;
    const int  maxN = (1<<9)+5;
     
    double pdMin[maxN];
    double pdMax[maxN];

    int digito[9] = {1,2,3,4,5,6,7,8,9};
    int soma(int mask){
        int sm = 0;
        for(int i = 0; i<9; i++){
            if(mask & (1<<i)) sm += digito[i];
        }
        return sm;
    }
     
    int transform(string numero){
        int mask = 0;
        for(int i = 0; i<numero.size(); i++){
            for(int d = 1; d<=9; d++){
                if(numero[i] == '0' + d) mask |= (1<<(d-1));
            }
        }
        return mask;
    }
     
    string reTransform(int mask){
        string numero;
        for(int i = 0; i<9; i++){
            if(mask & (1<<i)) numero += digito[i]+'0';
        }
        return numero;
    }
     
    double concat(int x){
        string f = reTransform(x);
        return double(stoi(f));
    }
     
    double solveMax(int mask, int inicio, int dado){
        if(pdMax[mask] > 0) return pdMax[mask];
        if(mask == 0) return 0;
        double fator = 1.0/36;
        if(inicio) fator = 1;
        double value = 0;
        string jogada = "-1";
        for(int dadoA = 1; dadoA <= 6; dadoA++){
            for(int dadoB = 1; dadoB <= 6; dadoB++){
                if(inicio && dadoA+dadoB != dado) continue;
                double maxJogada = -1;
                int flag = 0;
                for(int jogadaMask = 1; jogadaMask < (1<<9); jogadaMask++){
                    if(soma(jogadaMask) == dadoA+dadoB && (jogadaMask & mask) == jogadaMask ) {
                        int z = mask ^ jogadaMask;
                        double l = solveMax(z,0,0);
                        if(l > maxJogada){
                            maxJogada = l;
                            flag = 1;
                            jogada = reTransform(jogadaMask);
                        }
                    }
                }
                if(flag == 0) maxJogada = concat(mask);
                if(inicio) value = max(value, fator * maxJogada);
                else value += fator * maxJogada;
                }
        }
     
        if(inicio){
            cout << jogada << " ";
        }
        return pdMax[mask] = value;
    }
     
    double solveMin(int mask, int inicio, int dado){
        if(pdMin[mask] > 0) return pdMin[mask];
        if(mask == 0) return 0;
        double fator = 1.0/36;
        if(inicio) fator = 1;
        double value = 0;
        if(inicio) value = 1e11;
        string jogada = "-1";
        for(int dadoA = 1; dadoA <= 6; dadoA++){
            for(int dadoB = 1; dadoB <= 6; dadoB++){
                if(inicio && dadoA+dadoB != dado) continue;
                double maxJogada = 1e11;
                int flag = 0;
                for(int jogadaMask = 1; jogadaMask < (1<<9); jogadaMask++){
                    if(soma(jogadaMask) == dadoA+dadoB && (jogadaMask & mask) == jogadaMask ) {
                        int z = mask ^ jogadaMask;
                        double l = solveMin(z,0,0);
                        if(l < maxJogada){
                            maxJogada = l;
                            flag = 1;
                            jogada = reTransform(jogadaMask);
                        }
                    }
                }
                if(flag == 0) maxJogada = concat(mask);
                if(inicio) 
                    value = min(value, fator * maxJogada);
                else value += fator * maxJogada;
                }
        }
        if(inicio){
            cout << jogada << " ";
        }
        return pdMin[mask] = value;
    }
     
     
     
    int main(){
        #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
        string state;
        int dadoA;
        int dadoB;
     
        
        cin >> state;
        cin >> dadoA >> dadoB;
        for(int i = 0; i<maxN; i++){
            pdMax[i] = -1.0;
            pdMin[i] = -1.0;
        }
        cout << fixed;
        cout << setprecision(5);
        cout<< solveMin(transform(state),1,dadoA+dadoB) << "\n";
        cout<< solveMax(transform(state),1,dadoA+dadoB)<< "\n";

    }