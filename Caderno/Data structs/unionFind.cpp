
// WEIGHTED QUICK UNION

int id[maxn], sz[maxn];

int find(int p){
    if (id[p] == p) return p;
    return id[p] = find(id[p]); // Fazendo com que o elemento aponte diretamente para o representate
}

void uni(int p, int q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
}

int main() {
    
    fr(i, n) id[i] = i, sz[i] = 1;
}
