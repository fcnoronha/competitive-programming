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
#define gnl cout << "\n"

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

vi a,b,c;
int bit[2200200];
int ans[200200];
int n;
map<int,int> id;
set<int> coord;
int clk=1;

int query(int ind){
    int ans = 0;
    for(int i=ind;i>0;i-=i&-i)
        ans+=bit[i];
    return ans;
}

void update(int ind, int val){
    for(int i=ind;i<1100100;i+=i&-i)
        bit[i]+=val;
}

void solve(vi& x, vi& y){

    vector<tuple<int,int,int>> aux;
    ms(bit,0);

    fr(i,n){
        aux.pb(make_tuple(x[i],y[i],i));
    }

    sort(all(aux));

    int ini=0;
    int end=0;

    while(ini<n){
        while( end+1<n && get<0>(aux[end+1])==get<0>(aux[end]) )
            end++;
        for(int i=ini;i<=end;i++){
            int val_x = get<0>(aux[i]);
            int val_y = get<1>(aux[i]);
            //assume que ganhei por x dos que ja adicionei
            //preciso agora ganhar de alguem por y
            if(query(val_y-1))
                ans[get<2>(aux[i])]=1;
        }
        for(int i=ini;i<=end;i++){
            int val_x = get<0>(aux[i]);
            int val_y = get<1>(aux[i]);
            update(val_y,1);
        }
        ini=++end;
    }

}

int main(){

    fastio

    cin >> n;

    a.resize(200200);
    b.resize(200200);
    c.resize(200200);

    fr(i,n){
        cin >> a[i] >> b[i] >> c[i];
        coord.insert(a[i]);
        coord.insert(a[i]-1);
        coord.insert(b[i]);
        coord.insert(b[i]-1);
        coord.insert(c[i]-1);
        coord.insert(c[i]);
    }

    for(auto x : coord)
        id[x]=clk++;

    fr(i,n){
        a[i]=id[a[i]];
        b[i]=id[b[i]];
        c[i]=id[c[i]];
    }

    // fr(i,n)
    //     cout << a[i] << " - " << b[i] << " - " << c[i] << endl;

    solve(a,b);
    solve(a,c);
    solve(b,c);

    int cnt =0;
    fr(i,n)
        if(!ans[i])
            cnt++;

    cout << cnt << endl;
    fr(i,n)
        if(!ans[i])
            cout << i+1 << " ";
    cout << "\n";

}
