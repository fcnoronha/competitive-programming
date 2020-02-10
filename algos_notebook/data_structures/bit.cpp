/*
	BINARY INDEXED TREE - FENWICK TREE

Data structure that supoport range and update queries, both in O(logn).
For [a, b] interval you have to do query(b) - query(a-1).
Must be index from 1, in the form [1, MAXN].
*/

#define MAXN 10000

int bit[MAXN];

// Initializing tree in O(n)
void build(){
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;

		update(x, i);
	}
}

// [1, i] sum query
int query(int p){
	int sum = 0;
    for (; p > 0; p -= p&-p) // Subtract last significant bit
    	sum += bit[p];
    return sum;
}

// Sum x on position i
void update(int p, int val){
	for (; p <= MAXN; p += p&-p)
		bit[p] += val;
}

