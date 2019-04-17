#include <bits/stdc++.h>
using namespace std;

int main(){
	int t = 0, a, b, s;
	
	cin >> t;
	for(int x = 0; x < t; x++) {
	    cin >> a >> b;
	    
	    if(a - b == 0 || a - b == 1 || a-b == -1){
	        cout << "Ok" << endl;
	    }
	    else {
	        s = a + b;
	        if(s%2 == 0) {
	             s = a + b;
	             cout << s / 2 << " " << s / 2  << endl;
	        }  
	        else {
	            s--;
	            cout << s / 2 << " " <<  (s / 2)+1  << endl;
	        }
	        
	    }
	    a = 0; b = 0;
	}        
	        
}
