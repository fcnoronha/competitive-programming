#include <iostream>
using namespace std;

#define MAXN 100100

int main(){

	int n,m,v_now,v_last;
	char lin_now,lin_prev;

	cin >> n >> m;

	v_last=-4;
	for(int i=0;i<m;i++){
		cin >> v_now >> lin_now;
		if(i==0)	lin_prev=lin_now;

		if(lin_now=='M' || (v_now-v_last<4 && lin_prev!=lin_now)){
			cout << "No" << endl;
			return 0;
		}

		lin_prev=lin_now;
		v_last=v_now;

	}

	cout << "Yes" << endl;

	return 0;
}