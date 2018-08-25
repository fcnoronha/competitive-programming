// http://www.codcad.com/problem/66

#include <bits/stdc++.h>
using namespace std;

int main(){
	int m = 0, n = 0, re[16];
	int h = 65;
	for(int i = 1; i <= 8; i ++){
		cin >> n >> m;
		
		if(n > m){
			re[i] = h;
		}
		else{
			re[i] = h + 1;
		}
		h = h + 2;
	}

	int hmm = 7;
    int hm = 8;
	for(int i = 9; i <= 12; i++){
		cin >> n >> m;
		
		if(n > m){
			re[i] = re[i-hm];
		}
		else re[i] = re[i-hmm];
		hm --;
		hmm --;
	}

	cin >> n >> m;
	if(n > m) re[13] = re[9];
	else re[13] = re[10];

	cin >> n >> m;
	if(n > m) re[14] = re[11];
	else re[14] = re[12];

	cin >> n >> m;
	if(n > m) re[15] = re[13];
	else re[15] = re[14];

	char res = re[15];

	cout << res << endl;
}