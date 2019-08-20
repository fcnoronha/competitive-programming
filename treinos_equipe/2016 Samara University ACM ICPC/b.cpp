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

#define fst first
#define snd second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n;
vector<pll> v;
int main(){
    fastio;
    cin >> n;
    vector<pii> in,v;

    int a,b;
    fr(i,n){
        cin>>a>>b;
        in.pb({a,b});
    }

    int cnt=0;
    for(auto x:in){
        v.pb({x.fst-x.snd,cnt++});
    }

    sort(all(v));
    ll ans=0,at=0;
    reverse(all(v));

    ans=in[ v[0].snd ].fst;
    at=v[0].fst;


    frr(i,v.size()-1){

        if(at < in[ v[i].snd ].fst){
            ans+=in[ v[i].snd ].fst - at;
            at = in[ v[i].snd ].fst;
        }


        at-= in[ v[i].snd ].snd ;
    }
    cout<<ans<<endl;
}
