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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n;

int memo[120000][2][92];
int acum[120000];
int seen[120000];
int boat[120000];

int pd(int ind, int state,  int fila){

  //state:
  // 0 = ponte fechada
  // 1 = ponte aberta

  if(ind>boat[n] && fila==0){
    if(state==0)
      return 0;
    else
      return 60;
  }

  int &pdm=memo[ind][state][fila];
  if(pdm!=-1) return pdm;

  pdm=INF;

  //talvez tenha corner com 0 barcos
  int now = seen[ind];
  int prim = now - fila + 1;

  //primeiro barco da fila estourou paciencia
  if(fila>0 && ind>boat[prim]+1800)
    return pdm;

  //nao faz nada
  pdm=min(pdm, state + pd( ind+1, state, fila + acum[ind+1]-acum[ind]));

  //inverter estado da ponte
  int newT = ind + 60;
  int somaBarcos = acum[ind+60]-acum[ind];
  pdm = min( pdm, 60 + pd( newT, !state, fila+somaBarcos) );

   //ponte aberta e tem barco
  if(fila>0 && state==1){
    somaBarcos = acum[ind+20] - acum[ind];
    newT = ind + 20;
    pdm = min( pdm, 20 + pd(newT, 1, fila + somaBarcos-1));
  }

  return pdm;

}

int main(){

    fastio

    cin >> n;

    ms(memo,-1);

    frr(i,n){
      int t; cin >> t;
      acum[t]=1;
      seen[t]=i;
      boat[i]=t;
    }

    frr(i,110000){
      seen[i]=max(seen[i],seen[i-1]);
      acum[i]+=acum[i-1];
    }

    cout << pd(1,0,seen[1]) << endl;

}
