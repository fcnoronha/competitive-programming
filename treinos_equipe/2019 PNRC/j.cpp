#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define inf 1000000
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair


int32_t main (){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,s;
    cin>>n>>s;
    int t=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        t=max(t,x);
    }
    t=t*s;
    cout<<(t+1000-1)/1000<<endl;


    return 0;
}
 