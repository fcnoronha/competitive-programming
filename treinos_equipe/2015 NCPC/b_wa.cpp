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
 
int DIR = 1;
int ESQ = 0;
 
int dir[10];
int pos[10];
int direcoes[8] = {ESQ, DIR, ESQ, DIR, ESQ, DIR, ESQ, DIR};
int n;
int v[10];
int t[10];
int vis[300300];

vector<int> perm;

int zz[10];
int acabou(){
    frr(i,n) {
        if(pos[i] != i) return 0;
    }
    return 1;
}

int fatorial(){
    int ans = 1;
    frr(i,n){
        ans *= i;
    }
    return ans;
}

int transforma(){
    int ret = 0;
    int pot = 1;
    frr(i,n){
        ret += v[i]*pot;
        pot *= 10;
    }
    return ret;
}

int salva(){
    frr(i,n) zz[i] = v[i];
}

int recupera(){
    frr(i,n) v[i] = zz[i];
}
 
int proximo(){
 
    frr(i,n){
        int x = v[i];
        if(dir[x] == ESQ){
            if(pos[x] > 1){
                pos[x]--;
                t[pos[x]] = v[i];
            }
            else{
                dir[x] = DIR;
                t[pos[x]] = v[i];
            }
        }
        else{
            if(pos[x] < n){
                pos[x]++;
                t[pos[x]] = v[i];
            }
            else{
                dir[x] = ESQ;
                t[pos[x]] = v[i];
            }
 
        }
    }
    frr(i,n) v[i] = t[i];
}


int destransforma(int x){
    int pot = 10;
    for(int i = n; i>= 1; i--){
        v[i] = x%pot;
        pot *= 10;
    }
}
 
 
int main(){
    fastio;
 
    cin >> n;
 
    frr(i,n){
        v[i] = i;
        pos[i] = i;
        dir[i] = direcoes[i-1];
    }
    int cnt = 0;
    int fat = fatorial();
    int funcionou = 1;
    do {
        funcionou = 1;
        int cnt = 0;
        do {   
            if(vis[transforma()] ){
                perm.clear();
                funcionou = 0;
                break;
            }
            vis[transforma()] = 1;
            perm.pb(transforma());
            proximo();
            

        } while (++ cnt < fat);

        next_permutation(direcoes, direcoes+n);
        ms(vis,0);

    } while(!funcionou);

    for(auto x : perm){
        destransforma(x);
        frr(i,n) cout << v[i] << " ";
        cout << endl;

    }
}