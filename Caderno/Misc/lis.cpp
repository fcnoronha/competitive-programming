// Binary search
int bb(vector<int> &v, int l, int r, int x){
	while (r - l > 1){
		int m = l + (r-l) / 
		if (v[m] >= x)
			r = m;
		else 
			l = m;
	}
	return r;
}

int lis(vector<char> &v){
	if (v.size() == 0)
		return 0;

	vector<int> ls(v.size(), 0); // lasgest subsequence
	int lng = 1;

	ls[0] = v[0];
	for (int i = 1; i < v.size(); i++){
		if (v[i] < ls[0]) // new smallest value
			ls[0] = v[i];

		else if (v[i] > ls[lng - 1]) // Extending longest subsequence
			ls[lng++] = v[i];

		else {
			aux[bb(aux, -1, lng-1, v[i])] = v[i];
		}
	}

	return lng;
}