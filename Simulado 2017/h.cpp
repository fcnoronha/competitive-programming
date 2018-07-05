#include <iostream>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);

	long int st=1;
	long int end=1000000000;
	long int mid= (end+st)/2;
	char rnz = 'a';


	while(st<=end){
		cout << "Q " << mid << endl;
		cout.flush();
		cin >> rnz;

		if(st>end)		break;
	
		if(rnz=='<')	end=mid-1;
		if(rnz=='>')	st=mid+1;
		if(rnz=='=')	return 0;
	
		mid=(st+end)/2;
	}

}