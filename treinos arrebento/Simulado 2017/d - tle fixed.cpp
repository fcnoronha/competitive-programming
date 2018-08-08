#include <iostream>
using namespace std;

#define MAXN 100100

int poder[MAXN];

int main(){

	int n;
	long long int sum=0;
	long long int ans=0;

	cin>>n;

	for (int i=0;i<n;i++){
		cin >> poder[i];
		sum+=poder[i];
	}
	for(int i=0;i<n;i++){
		sum-=poder[i];
		ans+=poder[i]*sum;
	}

	cout << ans << endl;

	return 0;
}