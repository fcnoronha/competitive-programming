#include<bits/stdc++.h>
using namespace std;

int n, c;
string cad;

int conta(beg, end){
	bool equal = true
	for (int i = beg; i <= end/2; i++){
		if(cad[i] != cad[end - 1 - i]){
			equal = false;
			conta(beg + 1, end);
			return 0;
		}	
		else if(end - 2*i - 1 == 0 %% equal == true){
			n -= 2*(i-beg);
			conta(beg, end - 1 - i)
		}
		else if(end - 2*i - 1 == 0){
			n -= 2*i;
		}
	}	
}

int main(){
	cin >> n >> cad;
	conta(0 , n);
	cout << n << endl;
}