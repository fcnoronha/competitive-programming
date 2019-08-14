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

#define fst first
#define snd second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n,m;
int stx,sty;
char mapa[1123][1123];
int visf[1123][1123],vis[1123][1123];

int mx[4]={0,0,1,-1};
int my[4]={1,-1,0,0};

queue<pii> filaf;



bool pode(int x,int y){
    if(x<0 or y<0) return false;
    if(x>=n or y>=m) return false;
    if(mapa[x][y]=='#') return false;

    return true;
}

void bfs_fogo(){

    pii aux;

    while(!filaf.empty()){
        aux=filaf.front();
        filaf.pop();

        fr(i,4)
            if(pode(aux.fst+mx[i],aux.snd+my[i]) and visf[aux.fst+mx[i]][aux.snd+my[i]]==-1 ){
                visf[aux.fst+mx[i]][aux.snd+my[i]]=visf[aux.fst][aux.snd]+1;
                filaf.push({aux.fst+mx[i],aux.snd+my[i]});
            }
    }
}
void bfs_cara(){
    queue<pii> fila;

    fila.push({stx,sty});
    vis[stx][sty]=0;

    pii aux;
    while(!fila.empty()){
        aux=fila.front();
        fila.pop();

        fr(i,4)
            if(pode(aux.fst+mx[i],aux.snd+my[i]) and vis[aux.fst+mx[i]][aux.snd+my[i]]==-1){
                vis[aux.fst+mx[i]][aux.snd+my[i]]=vis[aux.fst][aux.snd]+1;
                fila.push({aux.fst+mx[i],aux.snd+my[i]});
            }
    }
}

void run(){
    ms(visf,-1);
    ms(vis,-1);
    int extx,exty;

    cin>>n>>m;

    string s;

    fr(i,n){
        cin>>s;
        fr(j,s.size()){
            mapa[i][j]=s[j];
            if(s[j]=='F'){
                filaf.push({i,j});
                visf[i][j]=0;
            }
            else if(s[j]=='S'){
                stx=i;
                sty=j;
            }
            else if(s[j]=='E'){
                extx=i;
                exty=j;
            }

        }
    }

    bfs_fogo();
    bfs_cara();

    if(vis[extx][exty]==-1){
        cout<<"N"<<endl;
        return;
    }
    if(visf[extx][exty]==-1){
        cout<<"Y"<<endl;
        return;
    }

    if(vis[extx][exty] < visf[extx][exty])
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;

}


int main(){
    fastio
    int t;
    cin>>t;
    while (t--) run();
}
