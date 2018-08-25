#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int xc, yc, rc, xb, yb, dist;
    cin >> xc >> yc >> rc >> xb >> yb;
    double andar;
    dist = (xc-xb)*(xc-xb) + (yc - yb)*(yc - yb);
    if(dist <= rc*rc){
        cout << "0.0000000000" << endl;
        return 0;
    }
    andar = sqrt((double) dist) - (double) rc;
    cout << fixed << setprecision(10) << andar << endl;
}


