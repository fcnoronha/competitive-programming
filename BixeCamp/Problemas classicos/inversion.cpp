// https://www.spoj.com/problems/INVCNT/

#include<bits/stdc++.h>
using namespace std;

long long int t, n, a;
int inf = INT_MAX;

long long int ms(vector<long long int> &v){
	long long int inv = 0;

	if(v.size() == 1) return 0;

	vector<long long int> u1, u2;
	for(int i = 0; i < v.size()/2; i++) u1.push_back(v[i]);
	for(int i = v.size()/2; i < v.size(); i++) u2.push_back(v[i]);

	inv += ms(u1);
	inv += ms(u2);

	u1.push_back(inf);
	u2.push_back(inf);

	int ini1 = 0, ini2 = 0;

	for(int i = 0; i < v.size(); i++){
		if(u1[ini1] <= u2[ini2]){
			v[i] = u1[ini1];
			ini1++;
		}
		else{
			v[i] = u2[ini2];
			ini2++;

			inv += (long long int)u1.size() - (long long int)ini1 - 1;
		}
	}

	return inv;
}

int main(){
	cin >> t;

	while(t--){
		cin >> n;

		vector<long long int> x;
		while(n--){
			cin >> a;
			x.push_back(a);
		}

		cout << ms(x) << endl;
	}
}