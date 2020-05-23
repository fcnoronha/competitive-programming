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
    
    int n;
    string s1,s2;
    cin>>n>>s1>>s2;

    int ig=0,di=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i])ig++;
        else di++;
    }

    cout<<min(ig,n)+min(di,((int)s1.size())-n)<<endl;
}
 