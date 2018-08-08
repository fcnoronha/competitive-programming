#include <bits/stdc++.h>
using namespace std;

int x[5000], y[5000], r[5000];


int dist(int x1, int y1, int r1, int x2, int y2, int r2){
    int overlap = 0;
	int dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    int r = (r1+r2)*(r1+r2);
    if(dist >= r) overlap = 1;
    return overlap;   
}

int main(){
    int q, j = 0;
    cin >> q;
    char t;
    int out = 0;
    for(int k = 0; k < q; k ++){
        cin >> t;
        int a, b, c;
        cin >> a >> b >> c;
        if(t == 'R'){
            for(int i = 0; i < j; i++){
                if(a == x[i]){
                    if(b == y[i]){
                        if(c == r[i]){
                            out = 1;
                            break;
                        }
                    }
                }
            }  
        }
        else{
            if(j == 0){
                out = 1;
                x[j] = a;
                y[j] = b;
                r[j] = c;
                j++; 
            }
            for(int i = 0; i < j; i++){
                if(dist(a, b, c, x[i], y[i], r[i]) == 0 && j!= 0){
                    out = 0;
                    break;
                }
                else{
                    out = 1;
                    x[j] = a;
                    y[j] = b;
                    r[j] = c;
                    j++;
                }
            }
        }
        if(out == 1) cout << "Ok" << endl;
        else cout << "No" << endl;    
    }
}
