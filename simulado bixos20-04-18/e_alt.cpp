#include <bits/stdc++.h>
using namespace std;

int frng[20],flag[20], mx, sum=0, n;



int main(){
    int ans;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> frng[i];
	    sum = sum+frng[i];
    }
    sort(frng,frng+n);
    flag[n-1] = 1;
    mx = frng[n-1];
    sum = sum - mx;
    if(mx >= sum){
        cout << mx - sum << endl;
        return 0;
    }
    bool loop = true;
    while(mx < sum && loop){
        for(int i = n-1; i >= 0; i--){
            if(flag[i] == 0 && mx + frng[i] <= sum - frng[i]){
                mx = mx + frng[i];
                sum = sum - frng[i];
                flag[i] = 1;
                break;
            }
            else if(i == 0) loop = false; 
        }       
    }
    cout << sum - mx << endl;
}


