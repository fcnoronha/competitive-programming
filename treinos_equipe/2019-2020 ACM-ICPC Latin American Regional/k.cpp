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

ll v[5005000];

int main(){
    fastio;

    string s;
    cin >> s;
    int n = s.size();
    ll indice = 2;
    vector<ll> raizes;
    for(int i = 0; i < n-1; i++){
        if(s[i] != s[i+1]) raizes.pb(indice+1ll);
        indice += 2;
    }
    if(raizes.size() == 0){
        if(s[0] == 'A'){
            cout << 0 << endl << -1 << endl;
        }
        else{
            cout << 0 << endl << 1 << endl;
        }
    }
    else{
        v[1] = 1;
        v[0] = -raizes[0];
        int i = 1;
        int grau = 1;
        while(i < raizes.size()){
            ll r = -1ll*raizes[i];
            grau++;
            for(int j = grau; j>=1; j--){
                v[j] = v[j-1] + v[j]*r;
            }
            v[0] *= r;
            i++;    
        }
        ll sinal = 1ll;
        if(s[n-1] == 'A') sinal = -1ll;
        cout << grau << endl;
        for(int j = grau; j>=0; j--){
            cout << sinal*1ll*v[j] << " ";
        }
        cout << endl;
    }

}