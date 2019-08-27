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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

ll val[30],val2[30];

int main(){
    fastio
    ll clk =1;
    ll q; cin >> q;
    val[1]=1;
    val[2]=2;
    val[3]=3;
    val[4]=3;
    val[5]=4;
    val[6]=10;

    val2[1]=1;
    val2[2]=2;
    val2[3]=2;
    val2[4]=2;
    val2[5]=3;
    val2[6]=5;
    val2[7]=10;

    while(q--){
        ll sumg=0;
        frr(i,6){
            ll x; cin >> x;
            sumg+=val[i]*x;
        }
        ll sumb=0;
        frr(i,7){
            ll x; cin >> x;
            sumb+=x*val2[i];
        }
        ll val=sumg-sumb;
        cout << "Battle " << clk++ << ": ";
        if(val>0)  cout << "Good triumphs over Evil" << endl;
        else if(val==0) cout << " No victor on this battle field" << endl;
        else       cout << "Evil eradicates all trace of Good" << endl;
    }
}
