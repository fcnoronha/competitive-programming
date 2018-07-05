#include <iostream>
using namespace std;

#define MAXN 100100

int main(){

	int n,aux;
	long int sum_odd=0;
	long int sum_even=0;
	long int ans=0;
	int n_odd=0;
	int min=1000000;

	cin >> n;

	for (int i=0;i<n;i++){
		cin >> aux;
		if(aux%2==0)	sum_even+=aux;
		else{
			n_odd++;
			sum_odd+=aux;
			if(aux<min)	min=aux;
		}			
	}
	ans+=sum_even;
	if(n_odd%2==0)	ans+=sum_odd;
	else{
		sum_odd-=min;
		ans+=sum_odd;
	}
	cout << ans << endl;
	return 0;
}