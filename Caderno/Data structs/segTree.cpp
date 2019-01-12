#include<bits/stdc++.h>
using namespace std;

#define MAXN 10011

int value[MAXN]; // Real values in each point of the tree
int seg[MAXN]; // Values in the tree nodes

// Segtree for minimum value

void update(int node, int i, int j, int idx, int val){

	if (i == j){
		seg[node] = val;
		value[idx] = val;
	}

	else {

		int left = 2*node;
		int right = 2*node + 1;
		int mid = (i+j)/2;

		if (idx <= mid) update(left, i, mid, idx, val);
		else 			 update(right, mid+1, j, idx, val);

		seg[node] = min(seg[right], seg[left]);
	}
}

int query(int node, int i, int j, int a, int b){
	// Return lowest value in [a, b]

	if (a <= i && j <= b) 
		return seg[node];

	if (i > b || a > j) 
		return INT_MAX;


	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	int ansl = query(left, i, mid, a, b);
	int ansr = query(right, mid+1, j, a, b);

	return min(ansl, ansr);
}