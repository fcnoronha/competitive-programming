#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;


int meses[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int mesesAc[13];
int vis[400];


void recupera(int dia){
    frr(i,12){
        if(dia <= meses[i]){
            if(i < 10) cout << 0;
            cout << i;
            cout << '-';
            if(dia < 10) cout << 0;
            cout << dia;
            return;
        }
        else{
            dia -= meses[i];
        }
    }
}


int main(){
    fastio;
    int n; cin >> n;
    frr(i,12){
        mesesAc[i] = mesesAc[i-1] + meses[i-1];
    }
    int ultimoDia = -1;
    int diaD = 301;
    fr(i,n){
        string s;
        cin >> s;
        string t;
        cin >> t;
        string a = t.substr(3,2);
        string b= t.substr(0,2);
        int dia = stoi(a);
        int mes = stoi(b);
        int diaT = mesesAc[mes] + dia;
        vis[diaT] = 1;
        if(diaT > ultimoDia) ultimoDia = diaT;
    }
    int dAns = -1;
    int ans = -1;
    int distanciaDans = INF;
    


    frr(i,365){
        if(vis[i]) {
            ultimoDia = i;
            continue;
        }  
        int d;
        int distanciaD;
        if(i < ultimoDia) d = 365 - ultimoDia + i;
        else d = i - ultimoDia;
        
        if(i < diaD) distanciaD = 365 - diaD + i;
        else distanciaD = i - diaD;

        if(d > dAns || (d == dAns && distanciaD < distanciaDans)){
            dAns = d;
            ans = i;
            distanciaDans = distanciaD;
        }
    }
    recupera(ans);
    cout << endl;
}
