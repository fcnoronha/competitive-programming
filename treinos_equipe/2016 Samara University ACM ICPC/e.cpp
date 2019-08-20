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


#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n;
set<int> coord;
vii pts;
map<int,int> id;

ll bit[1200100];

ll query(int ind){
    int ans = 0;
    for(int i=ind;i>0;i-=i&-i)
        ans+=bit[i];
    return ans;
}

void update(int ind, ll val){
    for(int i=ind;i<1200100;i+=i&-i)
        bit[i]+=val;
}

bool comp(pii a, pii b){
    if(a.snd!=b.snd)
        return a.snd<b.snd;
    return a.fst<b.fst;
}

int main(){
    fastio
    cin >> n;
    frr(i,n){
        int a,b;
        cin >> a >> b;
        coord.insert(a-1);
        coord.insert(a);
        coord.insert(a+1);
        coord.insert(b-1);
        coord.insert(b);
        coord.insert(b+1);
        pts.pb({a,b});
    }
    int clk=1;
    for(auto x : coord)
        id[x]=clk++;
    sort(all(pts),comp);
    ll xl=-1;
    ll yl=-1;
    fr(i,n){
        ll x = id[pts[i].fst];
        ll y = id[pts[i].snd];
        pts[i].fst=x;
        pts[i].snd=y;
        xl=max(xl,x);
        yl=max(yl,y);
        update(x,1);
        update(y+1,-1);
    }
    // for(auto x : pts){
    //     cout << x.fst << " - " << x.snd << endl;
    //  }
    ll ans = 0;
    // dbg(xl);
    // dbg(yl);
    for(ll i=xl;i<=yl;i++){
        // dbg(i);
        ll aux = query(i);
        // dbg(aux);
        ans=max(ans,aux);
    }
    cout << ans << endl;
}
