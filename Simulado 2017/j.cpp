#include <bits/stdc++.h>
using namespace std;

int main() {
	int n , m, a[10000], ant;
	char c[10000], antc;
	
	cin >> n >> m;
	for(int x = 0; x< m; x++) {
	  cin >> a[x] >> c[x];
	  if (c[x] == 'N') {
	    cout << "No" << endl;
	    return 0;
	  }
	  else if(a[x]-ant < 5) {
	    if(c[x] != antc && c[x] != 'N') {
	      cout << "No" << endl;

	      return 0;
	    }
	  }
	  else{
	    ant = a[x];
	    antc= c[x];
	  }
	}
	cout << "Yes" << endl;
}

