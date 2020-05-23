#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define inf 1000000
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define int long long
#define mod 1000000009

pair<int,int> memo[1123][212];

int tto[212];

int k;

//qtos jeitos, qtos 1
pii dp(int x,int b){
    if(b==1){
        if(k==1)return mp(2,1);
        if(x==1)return mp(1,1);
        if(x==0)return mp(1,0);
        return mp(0,0);
    }
    pii &resp=memo[x][b];
    if(resp.f==-1){
        pii c0=dp(x,b-1);
        pii c1=dp(((((x-tto[b-1])%k)+k)%k),b-1);
        resp.f=(c0.f+c1.f)%mod;
        resp.s=(c0.s+c1.f+c1.s)%mod;
    }
    //cout<<x<<" "<<b<<" "<<resp.f<<" "<<resp.s<<endl;
    return resp;
}

int32_t main (){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int b;
    cin>>k>>b;
    for(int i=0;i<1123;i++){
        for(int j=0;j<212;j++){
            memo[i][j]=mp(-1,-1);
        }
    }
    tto[0]=1;
    for(int i=1;i<212;i++){
        tto[i]=(tto[i-1]*2)%k;
    }

    cout<<(dp(0,b).s)%mod<<endl;



    return 0;
}
 