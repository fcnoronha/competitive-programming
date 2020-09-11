// LIS - LONGEST INCREASING SUBSEQUENCE
// O(n*logn)

int lis(vector<int> &v){
	vector<int> st; 
	for (auto x: v) {
		auto it = lower_bound(st.begin(), st.end(), x);
		if (it == st.end()) st.pb(x);
		else *it = x;
	}
	return st.size();
}
// change lower_bound to upper_bound if we want to consider repetition

vector<int> glis; // Will be stored here
#define MAXN 10010 // TO BE DEFINED

void get_lis(vector<int> &v) {
	vector<int> st; // stack
	int pos[MAXN], ft[MAXN]; // Position and father
	for (int i = 0; i < v.size(); i++){
		auto it = lower_bound(st.begin(), st.end(), v[i]);
		int p = it - st.begin();
		if (it == st.end()) st.pb(v[i]);
		else *it = v[i];
		pos[p] = i;
		if (p == 0) ft[i] = -1;
		else ft[i] = pos[p-1];
	}

	int p = pos[st.size() - 1];
	while (p >= 0){
		glis.pb(v[p]);
		p = ft[p];
	}

	reverse(glis.begin(), glis.end());
}