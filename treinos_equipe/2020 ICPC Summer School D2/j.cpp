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

int adj[1001][1001];
int restantes[100100];
int main(){
    fastio;
    ll k;
    cin >> k;
    vector<ll> fatores;
    for(int i = 0; i<32; i++){
        if(k&(1<<i)) fatores.pb((i));
    }

    ll maxn = -1;
    int cnt = 3;
    maxn = *fatores.rbegin();
    vector<ll> ultimos;
    int flag = 0;
    restantes[0] = 2;
    for(ll x : fatores){
        ultimos.clear();
        ultimos.pb(1);
        int n = x;
        for(int i = 0; i< n; i++){
            int a = cnt++;
            int b = cnt++;
            for(ll y : ultimos){

                adj[y][a] = 1;
                adj[a][y] = 1;
                adj[y][b] = 1;
                adj[b][y] = 1;

            }
            ultimos.clear();
            ultimos.pb(a);
            ultimos.pb(b);
        }
        
        int restante = maxn - n;
        if(!flag){
            fr(i,restante){
                int novo = cnt++;
                for(ll y : ultimos){
                    adj[y][novo] = 1;
                    adj[novo][y] = 1;
                }
                restantes[restante-i] = novo;
                ultimos.clear();
                ultimos.pb(novo);
            }

            for(auto y : ultimos){
                adj[y][2] = 1;
                adj[2][y] = 1;
            }
            flag = 1;
        }
        else{
            int cara = restantes[maxn-n];
            for(auto y : ultimos){
                adj[y][cara] = 1;
                adj[cara][y] = 1;
            }
        }

    }

    cout << cnt-1 << endl;


    frr(i,cnt-1){
        frr(j,cnt-1){
            if(adj[i][j]) cout << "Y";
            else cout << "N";
        }
        cout << endl;
    }
}
