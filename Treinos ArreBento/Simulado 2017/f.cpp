#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, aux;
	cin >> n;
	int sum = 0;
	for(int i = 0; i< n; i++){
	    cin >> aux;
	    sum+=aux;
	}
    sum=sum+4;
    sum=sum/5;
    cout << sum << endl;
}