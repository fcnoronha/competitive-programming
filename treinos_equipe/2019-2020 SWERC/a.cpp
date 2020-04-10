#include<bits/stdc++.h>
#define MAX 1123
#define f first
#define s second
using namespace std;

vector<pair<int, int>> adj[MAX];

pair<int, int> esta[MAX];
int xs, ys, xd, yd, b, c0, t, custo[MAX], n, dista[MAX][112];

int dist(int xa, int ya, int xb, int yb){
    return (int)ceil(sqrt((xb-xa)*(xb-xa) + (yb-ya)*(yb-ya)));
}

int dijkstra(){    
    // < custo, <distacia, no> >
    set<pair<int, pair<int, int>>> fila;
    fila.insert({0, {0, n}});
    while(!fila.empty()){
        int custo_atual, dist_atual, no_atual;
        auto it = *fila.begin();
        custo_atual = it.f;
        dist_atual = it.s.f;
        no_atual = it.s.s;
        fila.erase(it);
        if(dist_atual > b) continue;
        if(custo_atual >= dista[no_atual][dist_atual]) continue;
        dista[no_atual][dist_atual] = custo_atual;
        if(no_atual == n+1) return custo_atual;
        int aux_custo, aux_dist, aux_no;
        for(auto & x : adj[no_atual]){
            aux_no = x.first;
            aux_custo = x.second;
            aux_dist = dist(esta[no_atual].f, esta[no_atual].s, esta[aux_no].f, esta[aux_no].s);
            fila.insert({custo_atual + aux_custo, {dist_atual + aux_dist, aux_no}});
        }
    }

    return -1;
}



int main(){
    cin >> xs >> ys >> xd >> yd;
    cin >> b;
    cin >> c0;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> custo[i+1];
    }

    cin >> n;
    esta[n].f = xs;
    esta[n].s = ys;
    esta[n+1].f = xd;
    esta[n+1].s = yd;
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= 100; j++)
            dista[i][j] = INT_MAX;
        
    
    for(int i = 0; i < n; i++){
        int l;
        cin >> esta[i].first >> esta[i].second >> l;
        int x, y;
        for(int j = 0; j < l; j++){
            cin >> x >> y;  // estação [0, n(, modal
            adj[i].push_back({x, y});
            adj[x].push_back({i, y});                   
        }
    }

    for(int i = 0; i < n; i++){
        for(auto & x : adj[i]){
            x.second = custo[x.second]*dist(esta[i].first, esta[i].second, esta[x.first].first, esta[x.first].second);
        }        
    }
    pair<int, int> x;
    for(int i = 0; i < n; i++){        
        x.first = i;
        x.second = c0*dist(esta[i].first, esta[i].second, esta[n].first, esta[n].second);
        adj[n].push_back(x);
        x.first = n+1;
        x.second = c0*dist(esta[i].first, esta[i].second, esta[n+1].first, esta[n+1].second);
        adj[i].push_back(x);
    }

    adj[n].push_back({n+1, c0*dist(esta[n].first, esta[n].second, esta[n+1].first, esta[n+1].second)});


    // n inicio
    // n+1 seria o fim
    cout << dijkstra() << endl;


    return 0;
}