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

vector< tuple<int,int,int> > zorcs,axes;
set<int> coord;
map<int,int> id;
int n,m;

multiset<tuple<int,int,int>> seg[3200200];   //guarda axes na forma (curve,wgt,id)
multiset<tuple<int,int,int>> v[400200];

int ans[400400];

void build(int node, int l, int r){


    if(l==r){
        seg[node].insert(make_tuple(INF,INF,INF));
        for(auto x : v[l])
            seg[node].insert(x);
        return;
    }

    int mid = (l+r)>>1;
    build(2*node,l,mid);
    build(2*node+1,mid+1,r);

    seg[node].insert(make_tuple(INF,INF,INF));
    for(auto x : seg[2*node])
        seg[node].insert(x);
    for(auto x : seg[2*node+1])
        seg[node].insert(x);

}

tuple<int,int,int> best(tuple<int,int,int> a, tuple<int,int,int> b){

    if(get<0>(a)<=get<0>(b))
        return a;
    else if(get<0>(a)==get<0>(b)){
        if(get<1>(a)<=get<1>(b))
            return a;
        return b;
    }
    else
        return b;

}

tuple<int,int,int> query(int node, int l, int r, int a, int b, tuple<int,int,int> val){

    if(r<a || l>b){
        return make_tuple(INF,INF,INF);
    }

    else if(a<=l && r<=b){
        auto it = seg[node].lower_bound(val);
        return *it;
    }

    int mid = (l+r)>>1;

    tuple<int,int,int> left = query(2*node,l,mid,a,b,val);
    tuple<int,int,int> right = query(2*node+1,mid+1,r,a,b,val);

    return best(left,right);

}

void update(int node, int l, int r, tuple<int,int,int> val){

    if(l==r){
        seg[node].erase(val);
        return;
    }

    int mid = (l+r)>>1;
    int who = get<1>(val);
    if(who<=mid)
        update(2*node,l,mid,val);
    else
        update(2*node+1,mid+1,r,val);
    seg[node].erase(val);

}

int main(){
    fastio

    cin >> n;

    frr(i,n){
        int wgt,curve;
        cin >> wgt >> curve;
        zorcs.pb(make_tuple(wgt,curve,i));
        coord.insert(wgt);
        coord.insert(curve);
    }

    cin >> m;

    fr(i,m){
        int wgt,curve;
        cin >> wgt >> curve;
        axes.pb(make_tuple(wgt,curve,i));
        coord.insert(wgt);
        coord.insert(curve);
    }

    int clk = 1;

    for(auto x : coord)
        id[x]=clk++;

    fr(i,n){
        int x = id[get<0>(zorcs[i])];
        int y = id[get<1>(zorcs[i])];
        get<0>(zorcs[i])=x;
        get<1>(zorcs[i])=y;
    }

    fr(i,m){
        int x = id[get<0>(axes[i])];
        int y = id[get<1>(axes[i])];
        get<0>(axes[i])=x;
        get<1>(axes[i])=y;
    }

    if(m<n){
        cout << -1 << endl;
        return 0;
    }

    sort(all(zorcs));
    reverse(all(zorcs));

    for(auto x : axes){
        v[get<0>(x)].insert(make_tuple(get<1>(x),get<0>(x),get<2>(x)));
    }

    build(1,1,8000  00);

    for(auto x : zorcs){
        int wgt = get<0>(x);
        int curve = get<1>(x);
        int id = get<2>(x);
        tuple<int,int,int> desired = make_tuple(curve,wgt,0);
        tuple<int,int,int> aux = query(1,1,800000,wgt,INF,desired);
        if(get<0>(aux)==INF){
            cout << -1 << endl;
            return 0;
        }
        ans[get<2>(x)]=get<2>(aux);
        update(1,1,800000,aux);
    }

    fr(i,n)
        cout << ans[i]+1 << " ";
    cout << "\n";

}
