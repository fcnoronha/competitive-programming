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


int main(){
    fastio
    int n,m;
    vi adj[212345];
    int freq[212345];
    ms(freq,0);

    cin>>n>>m;

    int a,b;
    fr(i,m){
        cin>>a>>b;
        freq[a]++;
        freq[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int bst,ind;
    ind=1;
    bst=freq[1];
    frr(i,n)
        if(freq[i]<bst){
            bst=freq[i];
            ind=i;
        }
    int ans[212345];
    frr(i,n) ans[i]=1;

    ans[ind]=0;
    for(auto x:adj[ind])
        ans[x]=0;
    frr(i,n)
        cout<<ans[i]<<" \n"[i==n];
}
