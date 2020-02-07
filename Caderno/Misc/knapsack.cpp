// KNAPSACK
// Whitout repetition O(n*m)

#define MAXN 3000 // Maximum number of objects
#define MAXS 3000 // Maximnum weight

int n, val[MAXN], wg[MAXN], memo[MAXN][MAXS];

int knapsack(int obj, int wg_max){
	
	if (memo[obj][wg_max] >= 0) return memo[obj][wg_max];
	if (obj == n || !wg_max) return memo[obj][wg_max] = 0;
	
	int dont = knapsack(obj+1, wg_max);
	if (wg[obj] <= wg_max){
		int put = val[obj] + knapsack(obj+1, wg_max - wg[obj]);
		return memo[obj][wg_max] = max(put, dont);
	}
	
	return memo[obj][wg_max] = dont;
}

int main(){
	memset(memo, -1, sizeof memo);

	knapsack(0, MAXS);
}