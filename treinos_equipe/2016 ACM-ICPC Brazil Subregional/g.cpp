
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define otp(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MAXN = 550;

int query(int x, int y, vector<vi>& bit){
        
    int resp=0;
    for(int i=x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j)
            resp+=bit[i][j];
    }
    return resp;
}

void update(int x, int y, int delta, vector<vi>& bit){
        
    for(int i=x;i<MAXN;i+=i&-i){
        for(int j=y;j<MAXN;j+=j&-j){
            bit[i][j]+=delta;
        }
    }
    
}

int main(){

    int n,p; cin >> n >> p;

    vector<vi> bitb(550),bitw(550);

    fr(i,550){
        bitb[i].resize(550);
        bitw[i].resize(550);
    }

    fr(i,p){    // black
        int x,y;
        cin >> x >> y;
        x=n-x+1;
        update(x,y,1,bitb);
    }


    fr(i,p){    // white
        int x,y;
        cin >> x >> y;
        x=n-x+1;
        update(x,y,1,bitw);
    }

    int answ=0,ansb=0;


    frr(i,n){
        frr(j,n){

            int mx= min(n-i+1,n-j+1);

            fr(k,mx){

                int pi = i-k;
                int pj = j-k;

                int nb=0,nw=0;
                
                int aux = query(pi+k,pj+k,bitb);

                aux-=query(pi+k,pj-1,bitb);
                aux-=query(pi-1,pj+k,bitb);
                aux+=query(pi-1,pj-1,bitb);

                nb=aux;

                aux = query(pi+k,pj+k,bitw);

                aux-=query(pi+k,pj-1,bitw);
                aux-=query(pi-1,pj+k,bitw);
                aux+=query(pi-1,pj-1,bitw);
                
                nw=aux;

                if(!nw && nb)
                    ansb++;
                if(nw && !nb)
                    answ++;
            }
        }
    }

    cout << ansb << " " << answ << endl;

}