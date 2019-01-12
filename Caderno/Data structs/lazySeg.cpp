// --LAZY SEG
// Atualiza o no so quando aql informaçao e realmente necessaria
// O(logn)

#include "bits/stdc++.h"
using namespace std;

#define MAXN 1001
int lazy[MAXN], seg[MAXN];

// Soma val em cada um dos indices no intervalor [a,b]
void update(int node, int i, int j, int a, int b, int val){
	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	// Caso existam operaçoes atrasadas
	if (lazy[node]){
		// Adicionando multiplicado devido ao numero de elementos
		seg[node] += lazy[node]*(j-i+1);

		if (i != j){
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}

		lazy[node] = 0; // Resseta
	}

	// Caso att nao afeta este no
	if (i > j || i > b || a > j) return;

	// Se a att pega o no inteiro
	if (a <= i && j <= b){
		seg[node] += val*(j-i+1);
		if (i != j){
			lazy[right] += val;
			lazy[left] += val;
		}
	}
	else {
		update(left, i, mid, a, b, val);
		update(right, mid+1, j, a, b, val);
		seg[node] = seg[left] + seg[right];
	}
}

int query(int node, int i, int j, int a, int b){
	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	if (lazy[node]){
		seg[node] += lazy[node]*(j-i+1);
		if (i != j){
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}

	// [i,j] e [a,b] sao disjuntos
	if (i > j || i > b || a > j) return 0;

	// Se [i,j] esta contido em [a,b]
	if (a <= i && j <= b)
		return seg[node];

	else {
		int sum_l = query(left, i, mid, a, b);
		int sum_r = query(right, mid+1, j, a, b);
		return sum_r + sum_l;
	}
}
