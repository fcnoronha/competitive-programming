#include <bits/stdc++.h>
using namespace std;

int one[1000], two[1000];

int main(){
    int n, m, mxone1 = 0, maxone2 = 0, sum = 0, mx = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> one[i];
        if(mxone1 < one[i]){
            maxone2 = mxone1;
            mxone1 = one[i];
        }
        else if(maxone2 < one[i]) maxone2 = one[i];
    }
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        mx = max(a,mx);
    }
    sum = mxone1 + maxone2;
    cout << max(sum, mx) << endl;
}
