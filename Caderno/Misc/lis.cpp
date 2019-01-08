// LIS - LONGEST INCREASING SUBSEQUENCE

// O(n*logn)

int lis(vector<int> &v){
	// Return size of the longest increasing subsequence in v

	vector<int> st; 

	for (int i = 0; i < v.size(); i++){

		// Iterator to the leftmost element of stack that isn't small than v[i]
		vector<int>::iterator it = lower_bound(st.begin(), st.end(), v[i]);

		// If it is the end of the vector, every element in st[] is smaller than v[i]
		if (it == st.end()) st.pb(v[i]);

		// We substitute value
		else *it = v[i];

	}

	return st.size();
}

// OBS: if we want it to accept repeated elements, in order to get a 
// non decreasing subsequence, we just have to change lower_bound to 
// upper_bound.

// If we want to get the actual LIS use the code bellow

vector<int> glis; // Will be stored here
#define MAXN 10010 // TO BE DEFINED

void lis(vector<int> &v){

	vector<int> st; // stack
	int pos[MAXN], ft[MAXN]; // Position and father

	for (int i = 0; i < v.size(); i++){

		vector<int>::iterator it = lower_bound(st.begin(), st.end(), v[i]);

		// Position of the element in the stack
		int p = it - st.begin();

		if (it == st.end()) st.pb(v[i]);
		else *it = v[i];

		pos[p] = i;

		// If its in the first stack
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