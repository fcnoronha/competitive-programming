#include<bits/stdc++.h>
using namespace std;

int nodes[4*MAX];
int com[4*maxn], fim[4*maxn];

node void; // A definir dependendo do problema, vai ser o elemento neutro

node build(int node, int comv, int fimv){ //funçao construtora da segtree
	com[node] = comv; // Setando inidio e fim que o node abrange
	fim[node] = fimv;
	if (comv == fimv) // Se e uma folha
		return seg[node] = v[comv]; // v e o vetor que guarda valores unitarios
	int meio = fimv - (fimv-conv)/2; // calculando a media para evitar overflow
	seg[node] = build(2*node, comv, meio) + build(2*node+1, meio+1, fimv);
	return seg[node];
}

node query(int node, int comq, int fimq){ // Retorna o valor do intervalor
	if (fim[node] < comq || com[node] > fimq) return void;
	if (com[node] >= comq && fim[node] <= fimq) return seg[node];
	return query(2*node, comq, fimq) + query(2*node+1, comq, fimq);
}

void change(int node, int i, int x){ // muda inesimo elemento pra x
	if (com[node] > i || fim[node] < i) return;
	if (com[node] == i && fim[node] == i){
		v[i] = x; // Atualizando vetor de valores
		seg[node] = x;
		return;
	}
	change(2*node, i, x); // Atualiza os filhos
	change(2*node + 1 , i, x);
	seg[node] = seg[2*node] + seg[2*node+1]; // Recalcula o segmento
}

