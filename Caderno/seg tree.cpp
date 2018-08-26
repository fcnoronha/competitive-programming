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

// --LAZY SEG
// Ideia de setar flags nos nodes, ou seja, se voce quer adicionar 2 em um segmento
// basta setar uma flag de adicionar 2 para aql seguimento, e depos, so na hora de 
// consultar eu calculo essa mudança. Para isso se usar um vetor lazy[].

// Definir funçao unlazy() que atualiza o valor do node autal e seta flags nos filhos

void unlazy(int node){
	if (lazy[node] == 0) return; // Nao tem nada no lazy
	if (com[node] == fim[node]){ // Caso seja uma folha
		seg[node] += lazy[node];
		lazy[node] = 0;
		return;
	}
	lazy[2*node] += lazy[node]; // Setando lazy nos filhos
	lazy[2*node+1] += lazy[node];
	seg[node] += (fim[node] = com[node]) * lazy[node]; // Atualizando meu segmento
	lazy[node] = 0; // Ressetando valor
}

void change_lazy(int node, int coma, int fima, int x){ // Atualiza na ideia de icrementar eleentos de um segmento
	unlazy(node); // att minha inf e jjogo pros meus filhos
	if (com[node] >= coma && com[node] <= fima){
		lazy[node] = x;
		return;
	}
	if (fim[node] < coma || com[node] > fima) return; // O node nao esta no intervalo que eu quero att
	change_lazy(2*node, coma, fima, x);
	change_lazy(2*node +1, coma, fima, x);
}