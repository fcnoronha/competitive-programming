// INVERSION COUNT USING MERGE SORT

int ic(vi &v){
	int inv = 0;
	if (v.size() == 1) return 0;
	
	vector<int> u1, u2; 
	for (int i = 0; i < v.size()/2; i++) u1.push_back(v[i]);
	for (int i = v.size()/2; i < v.size(); i++) u2.push_back(v[i]);

	inv += ic(u1); inv += ic(u2);
	u1.push_back(INT_MAX); u2.push_back(INT_MAX);

	int ini1 = 0, ini2 = 0;
	for (int i = 0; i < v.size(); i++){
		if (u1[ini1] <= u2[ini2])
			v[i] = u1[ini1++];
		else {
			v[i] = u2[ini2++];
			inv += u1.size() - ini1 - 1;
		}
	}
	return inv;
}