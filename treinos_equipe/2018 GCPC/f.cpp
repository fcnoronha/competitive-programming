#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(iii, x.size()) cout << x[iii] << " \n"[iii==x.size()-1]
#define pvv(x, n) for(int iii = 1, vaca = nnn; i <= nnn;i++) cout << x[i] << " \n"[iii==nnn];

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
const int N = 1e3 + 1;

vector<ll> fibos;
ll v[100100];
pll indices[200200];

int main(){

    ll n;
    cin >> n;
    ll primeiro = -1;
    ll segundo = -1;
    int flag = 0;
    fr(i,n){
        cin >> v[i];
        if(v[i] == 1 && !flag){
            primeiro = i;
            flag = 1;
        }
        else if(v[i] == 1 && flag){
            segundo = i;

        }
    }

    if(segundo != -1){
        cout << primeiro+1 << " " << segundo+1 << endl;
        return 0;
    }
    ll antant = 0;
    ll ant = 1;
    fibos.pb(0);
    ll max = *max_element(v,v+n)+5;
    while(true){
        ll novo = ant + antant;
        if(novo >= max) break;
        fibos.pb(novo);
        antant = ant;
        ant = novo;

    }
    ll cnt = 0;
    fr(i,n){

        ll x = *lower_bound(all(fibos), v[i]);
        ll ind = lower_bound(all(fibos), v[i]) - fibos.begin();

        if(x != v[i]) continue;
        indices[cnt++] = {ind, i};
    }
    sort(indices, indices+cnt);

    fr(i, cnt-1){

        if(indices[i].f + 1ll == indices[i+1].f){
            cout << indices[i].s + 1 << " " << indices[i+1].s + 1 << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;


}
