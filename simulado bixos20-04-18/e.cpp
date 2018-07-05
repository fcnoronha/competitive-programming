#include <bits/stdc++.h>
using namespace std;

int frng[200],sum=0,sum_comp,dif,n,ans;

void rec(int index, int acum){


    if(index==n){
        if( abs(2*acum-sum) <=abs(2*ans-sum) )  ans=acum;
        return;
    }
    
    rec(index+1,acum);
    rec(index+1,acum+frng[index]);

}

int main(){
 
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> frng[i];
        sum+= frng[i];
    }
    
    ans=sum;
    rec(0,0);
    cout << abs(2*ans-sum) << endl;
    
}


