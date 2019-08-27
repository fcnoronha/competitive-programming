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

int n;
int v[500500];
ll bit[500500];

ll query(int ind){
    ll ans=0;
    for(int i=ind;i>0;i-=i&-i)
        ans+=bit[i];
    return ans;
}

void update(int ind, ll val){
    for(int i=ind;i<500500;i+=i&-i)
        bit[i]+=val;
}

void go(){

    map<string, int> id;

    string aux;

    int clk = 1;

    frr(i,n){
        cin >> aux;
        id[aux]=clk++;
    }

    frr(i,n){
        cin >> aux;
        v[i]=id[aux];
    }

    ms(bit,0);

    ll inv = 0;

    for(int i=1;i<=n;i++){
        inv+=query(500000)-query(v[i]);
        update(v[i],1);
    }

    cout << inv << endl;

}

int main(){

    fastio;

    while( (cin >> n ) && n)  go();

}
