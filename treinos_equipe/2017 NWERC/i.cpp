#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i, n) for (int i = 0; i < n; i++)
#define frr(i, n) for (int i = 1; i <= n; i++)
#define ms(x, i) memset(x, i, sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define olar cout << "olar" << endl
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
 
const int INF = 0x3f3f3f3f;
 
 struct celula {
	int d, s, i;
	bool operator<(const celula &other) const {
		return d-s > (other.d-other.s);
	}
};
pair<int,pair<int,int>> v[100100];
 
int pd[600][1000];
int zz[100100];
int option[1000][1000];
celula celulas[100100];
vector<int> numeros;
int n;
void recupera(int i, int j){
    if(i==0 && j ==0){
        int j = n;
    while(pd[n][j] == INF) j--;
	for (int i = n; i > 0; i--) {
		if (option[i][j] == 1) {
            numeros.pb(i-1);
            j--;
        }
	}
    reverse(all(numeros));
	cout << numeros.size() << endl;
    for(auto x : numeros){
        cout << celulas[x].i << " ";
    }
    cout << endl;
    }
    if(i <= 0 || j <= 0) return;
    if(option[i][j] == 1){
        numeros.pb(v[i].snd.snd);
        recupera(i-1,j-1);
    }
    else recupera(i-1,j);
}
 
int main(){
    fastio;
    int c;
    cin >> n >> c;
    for(int i = 0; i<n; i++){
        int d, s;
        cin >> d >> s;
        celulas[i].d = d;
        celulas[i].s = s;
        celulas[i].i = i+1;
    }
	sort(celulas,celulas+n);
	for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++){
            pd[i][j] = INF;
        }
    }
	pd[0][0] = 0;
	/*
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(pd[i-1][j-1] < INF) {
                if(pd[i-1][j] < pd[i][j]){
                    pd[i][j] = pd[i-1][j];
                    option[i][j] = 0;
                }
                if(pd[i-1][j] + max(celulas[i-1].d, celulas[i-1].s) > c) continue;
                if(pd[i-1][j-1] + celulas[i-1].s < pd[i][j]){
                    pd[i][j] = pd[i-1][j-1] + celulas[i-1].s;
                    option[i][j] = 1;
                }
            }
        }
    }
    /*
   for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            pd[i][j] = pd[i-1][j];
            if(pd[i-1][j-1] <= pd[i][j] && pd[i-1][j-1]+max(zz[v[i].snd.snd],v[i].snd.fst) <= c)
            pd[i][j] = pd[i-1][j-1]+v[i].snd.fst;
            if(pd[i-1][j] < pd[i-1][j-1]+v[i].snd.fst)
                option[i][j] = 0;
            else 
                option[i][j] = 1;
        }
    }
    */
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (pd[i][j] == INF) continue;
			if (pd[i][j] < pd[i+1][j]) {
                pd[i+1][j] = pd[i][j];
                option[i+1][j] = 0;
            }
			if (pd[i][j] + max(celulas[i].d,celulas[i].s) <= c && pd[i][j] + celulas[i].s < pd[i+1][j+1]) {
				pd[i+1][j+1] = pd[i][j] + celulas[i].s;
				option[i+1][j+1] = 1;
			}
		}
    }
    recupera(0,0);
	
    
}