#include <bits/stdc++.h>
using namespace std;

int pts[4];
int aux,pos,n;
int winner=-1;
string ans="ABCD";

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        pos=i%4;
        cin>>aux;
        pts[pos]+=aux;
    }
    
    for(int i=0;i<4;i++){
    
        if(winner==-1)   winner=0;
        
        else{
            if(pts[i]>pts[winner])      winner=i;
            if(pts[i]==pts[winner])     winner=min(winner,i);
        }

	}
	
	cout << ans[winner] << endl;
	return 0;
	
 }
