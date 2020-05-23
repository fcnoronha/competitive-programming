#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define inf 1000000
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define int long long
#define mod 998244353

int n,k;

map<int,int> q;

vector<int> v;

int memo[1123][1123];

int dp(int i,int f){
    if(f==0)return 1;
    if(i==v.size())return 0;
    int &resp=memo[i][f];
    if(resp==-1){
        resp=(dp(i+1,f)+q[v[i]]*dp(i+1,f-1))%mod;
    }
    return resp;
}


int32_t main (){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q[x]++;
    }
    for(auto x:q){
        v.pb(x.f);
    }
    for(int i=0;i<1123;i++){
        for(int j=0;j<1123;j++)memo[i][j]=-1;
    }
    cout<<dp(0,k)%mod<<endl;



    return 0;
}
 