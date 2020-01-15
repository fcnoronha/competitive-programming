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

ll precalc[(int)1e7];

int main(){
    ll M; scanf("%lld", &M);
    for(ll n = 3; n <= 54;n++){
        ll sm = 0;
        for(ll i = 1; i <= (int)1e8; i++){
            if(i < (int)1e7 && precalc[i] == 0){
                precalc[i] = i*i;
            }
            else if(i < (int)1e7) precalc[i] *= i;
            if(M - precalc[i] == sm){
                printf("%lld %lld\n", n, i);
                return 0;
            }
            else if(M - precalc[i] < sm) break;
            sm += precalc[i];
        }
    }
    printf("impossible\n");

}
