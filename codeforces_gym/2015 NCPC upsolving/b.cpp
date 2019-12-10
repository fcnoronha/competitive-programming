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
 
int main(){
    fastio;

    int n;
    cin >> n;

    if (n == 0) {
        p("");
        return 0;
    }
    if (n == 1) {
        p(1);
        return 0;
    }
    if (n == 2) {
        cout << "1 2\n2 1\n";
        return 0;
    }

    vector<vi> perm = {{1,2},{2,1}};
    for (int i = 3; i <= n; i++) {

        vector<vi> aux;

        for (auto v : perm) 
            fr(j, i)
                aux.pb(v);
        
        perm = aux;
        vi ord;
        fr(j, i) ord.pb(j);
        reverse(all(ord));

        for (int k = 0; k < perm.size(); k++) {
            
            auto &v = perm[k];
            int idx = k%i;
            int pos = ord[idx];

            vi x;
            fr(j, pos) x.pb(v[j]);
            x.pb(i);
            for(int j = pos; j < v.size(); j++) x.pb(v[j]);
            v = x;

            if (idx == i-1) reverse(all(ord));
        }
    }

    for (auto v : perm) pv(v);
}