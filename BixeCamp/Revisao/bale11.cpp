// https://br.spoj.com/problems/BALE11/
#include<bits/stdc++.h>
using namespace std;

int n, a;
long long int s = 0, r = 0;


int ms(vector<int> &v){
	int inv = 0;
	int s = v.size();

	if(s == 1) return 0;

	vector<int> u1, u2;
	for(int i = 0; i < s/2; i++) u1.push_back(v[i]);
	for(int i = s/2; i < s; i++) u2.push_back(v[i]);

	inv += ms(u1);
	inv += ms(u2);

	u1.push_back(INT_MAX);
	u2.push_back(INT_MAX);

	int ini1 = 0, ini2 = 0;

	for(int i = 0; i < s; i++){
		if(u1[ini1] <= u2[ini2]){
			v[i] = u1[ini1];
			ini1++;
		}
		else{
			v[i] = u2[ini2];
			ini2++;

			inv += u1.size() - ini1 - 1;
		}
	}

	return inv;
}


int main(){
	cin >> n;
	vector<int> x;

	while(n--){
		cin >> a;
		x.push_back(a);
	}
	
	cout << ms(x) << endl;
}
