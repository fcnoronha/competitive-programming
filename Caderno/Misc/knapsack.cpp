// KNAPSACK
// Whitout repetition

MAXN // Maximum number of objects
MAXS // Maximnum weight

int n, val[MAXN], wg[MAXN], tab[MAXN][MAXS];
// Tab stores the maximum value we can get in the i-th object

memset(tab, -1, sizeof tab);

int knapsack(int obj, int wg_max){
	// obj = actual object, index
	// wg_max = maximum weight available

	if (tab[obj][wg_max] >= 0) return tab[obj][wg_max];

	// If there's no more objects or weight left in the bag
	if (obj == n || !wg_max) return tab[obj][wg_max] = 0;

	// Next object, without actual one
	int dont = knapsack(obj+1, wg_max);

	// If its possible to get actual objetct
	if (wg[obj] <= wg_max){
		// Dp itself
		int put = val[obj] + knapsack(obj+1, wg_max - wg[obj]);
		// Best between put or dont put
		return tab[obj][wg_max] = max(put, dont);
	}

	// If there's not possible to put actual object
	return tab[obj][wg_max] = dont;
}

int main(){
	memset(tab, -1, sizeof tab);

	knapsack(0, MAXS);
}