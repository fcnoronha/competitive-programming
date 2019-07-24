#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(long long int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";
#define olar cout << "OLAR\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

long long int zz[101];
long long int kk[101];
long long int vis[101];

long long int ped[101][101];
long long int road[101][101];

long long int chv;

void dij1(long long int k){

    set<pair<long long int,long long int>> fila;

    for(long long int i = 1; i<= 100; i++) {
        zz[i] = INF;
        vis[i] = 0;
    }
    zz[k] = 0;
    fila.insert({0,k});

    while(!fila.empty()){
        auto atual = fila.begin();
        fila.erase(atual);
        long long int x = (*(atual)).s;
        if(vis[x]) continue;
        vis[x] = 1;

        for(long long int i = 1; i <= 100; i++){
            long long int w = ped[x][i];
            if(road[x][i] != -1) w = 0;
            if( w!=-1 && zz[i] > zz[x] + w){
                zz[i] = zz[x] + w;
                fila.insert({zz[i], i});
            }

        }
    }
}

void dij2(long long int k, long long int y){

    set<pair<long long int,long long int>> fila;

    chv = zz[y];
    for(long long int i = 1; i<=100; i++) {
        zz[i] = INF; // Dist final
        vis[i] = 0;
        kk[i] = 0; // dist com chuva
    }


    zz[k] = 0;
    fila.insert({0,k});

    while(!fila.empty()){

        auto atual = fila.begin();
        fila.erase(atual);
        long long int x = (*(atual)).s;
        if(vis[x]) continue;
        vis[x] = 1;

        for(long long int i = 1; i<= 100; i++){

            long long int w = ped[x][i];
            if(road[x][i] != -1) w = road[x][i];

            if(w!=-1 && zz[i] > zz[x] + w){
                if(road[x][i] == -1 && kk[x] + ped[x][i] > chv) continue;
                if(road[x][i] == -1){
                    kk[i] = kk[x] + ped[x][i];
                }
                zz[i] = zz[x] + w;
                fila.insert({zz[i],i});
            }
        }
    }

}



int main(){
	fastio
    long long int t;
    cin >> t;
    while(t--){
        long long int n, m;
        cin >> n >> m;

        for(long long int i = 1; i<= 100; i++){
            for(long long int j = 1; j<=100; j++){
                ped[i][j] = -1;
                road[i][j] = -1;
            }
        }

        for(long long int i = 0; i<m; i++){
            long long int a,b,c,k;
            cin >> a >> b >> c >> k;
            if(k == 1){
                ped[a][b] = c;
                ped[b][a] = c;
            }
            else{
                road[a][b] = c;
                road[b][a] = c;
            }
        }

        long long int x,y;
        cin >> x >> y;
        dij1(x);
        if(zz[y] == INF){
            cout << -1 << "\n";
        }
        else{
            dij2(x,y);
            cout << chv << " " << zz[y] <<  "\n";
        }

    }


}
