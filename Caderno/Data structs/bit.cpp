/*
	
	BINARY INDEXED TREE - FENWICK TREE

Data structure that supoport range and update queries, both in O(logn).

For [a, b] interval you have to do query(b) - query(a-1).

Must be index from 1, in the form [1, MAXN].

*/

#define MAXN 10000

// Global arrays
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
int query(int i){
	int sum = 0;
    for (; i > 0; i -= i&-i) // Subtract last significant bit
    	sum += bit[i];
    return sum;
}

// Sum x on position i
void update(int x, int i){
	for (; i <= MAXN; i += i&-i)
		bit[i] += x;
}

