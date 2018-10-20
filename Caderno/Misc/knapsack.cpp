// KNAPSACK
// Sem repetiçao

MAXN // Maximo de elementos
MAXS // Peso maximo


int n, val[MAXN], wg[MAXN], tab[MAXN][MAXS];

memset(tab, -1, sizeof tab);



int knapsack(int obj, int wg_max){
	if (tab[obj][wg_max] >= 0) return tab[obj][wg_max];

	// Se nao houver mais objetos ou espaço na mochila
	if (obj == n || !aguenta) return tab[obj][wg_max] = 0;

	// Proximo obj, sem colocar atual
	int dont = knapsack(obj+1, wg_max);

	// Se for possivel colocar obj
	if (wg[obj] <= wg_max){
		// PD em si
		int put = val[obj] + knapsack(obj+1, wg_max - wg[obj]);
		// Melhor entre colocar ou nao
		return tab[obj][wg_max] = max(put, dont);
	}

	// Caso nao fosse possivel colocar objeto
	return tab[obj][wg_max] = dont;
}

int main(){
	memset(tab, -1, sizeof tab);

	knapsack(0, s); // Onde s e o peso maximo
}