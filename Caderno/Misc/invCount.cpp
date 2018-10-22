#include<bits/stdc++.h>
using namespace std;

int ic(vector<int> &v){

	int inv = 0;

	if (v.size() == 1) return 0;

	vector<int> u1, u2; // Um vetor para cada metade

	for (int i = 0; i < v.size()/2; i++)
		u1.push_back(v[i]);

	for (int i = v.size()/2; i < v.size(); i++)
		u2.push_back(v[i]);

	inv += ic(u1);
	inv += ic(u2);

	u1.push_back(INT_MAX);
	u2.push_back(INT_MAX);

	int ini1 = 0, ini2 = 0;

	for (int i = 0; i < v.size(); i++){
		// se o menor de u1 for menor que o de u2
		if (u1[ini1] <= u2[ini2])
			v[i] = u1[ini1++];

		else {
			v[i] = u2[ini2++];

			// Incremento com o numero de elementos em u1
			inv += u1.size() - ini1 - 1;
		}
	}

	return inv;
}

int main(){

	vector<int> v;
	v.push_back(5);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(7);
	v.push_back(6);

	cout << ic(v) << endl;
}