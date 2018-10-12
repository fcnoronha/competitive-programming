// Dados dois compenentes/conjuntos, realizar operaçao de busca (saber se dados elementos estao ligados
//  um ao outro) e de ligaçao (ligar dois elementos, podendo assim realizar um ligaçao entre conjuntos).

// Vetor id[] me da o representate da componente/classe de um dado i
//	-Inicialmente, o representante de classe de um dado i sera ele mesmo;

// -----------------

// QUICK FIND 
// Variaçao que realiza busca em O(1) e union em O(n)

// Definindo uma funçao para saber a classe de um elemento
int find(int p){
	return id[p];
}

// Definindo um funçao para saber se dois elementos estao na mesma classe
bool compare(int p, int q){
	return id[p] == id[q];
}

// Definindo uma funçao para unir dois elementos, ou seja, unir duas classes
void uni(int p, int q){
	p = find(p); // Fazendo com que cada variavel assuma seu representante
	q = find(q);
	for (int i = 0; i < n; i++) 
		// Fazendo com que todos elementos da classe p virem da classe q
		if (id[i] == p) id[i] = q;	
}

// -----------------

// QUICK UNION
// Aqui, ambas as funçoes tomam O(n)

// Neste find() faremos com que cada elemento aponte para um outro elemento, ate que cheguemos ao representante
int find(int p){
	if (id[p] == p) return p;
	return find(id[p]);
}

// Defindo a funçao de uniao, que faz com que o representante de uma classe aponte para o representante da outra
void uni(int p, int q){
	p = find(p); // Variavel assume seu representante
	q = find(q);
	id[p] = q; 
}

// -------------------

// WEIGHTED QUICK UNION
// Agora, neste modelo, vamos imaginar as componentes como arvores, sendo a raiz de cada arvore a representante.
// A operaçao de union, agora, liga a raiz das duas arvores, permanecendo a raiz da maior como reprensentante.
// Definiremos um vetor sz[], que guardara o tamhanho da arvore. Inicializado com 1's.

void uni(int p, int q){
	p = find(p);
	q = find(q);
	
	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q); // Garantindo que p e a menor arvore

	id[p] = q;
	sz[q] += sz[p];
}
// Se mortamos a arvores desta maneira, temos que a complexidade do find(), e portanto, do uni() sera no maximo 
// O(log n), onde n e o numero de elementos

// Ademais, podemos realizar uma pequena mudança no find
int find(int p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]); // Fazendo com que o elemento aponte diretamente para o representate
}
// Com essa mundança, a complexidade de find fica praticamente O(1)

// Assim, fazemos com que as duas operaçoes fiquem praticamente constantes.