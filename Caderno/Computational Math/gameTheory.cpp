// GAME THEORY - GRUNDY NUMBER

/*

	First case: pile of coins, where a player can take any quantity Xi
	, Xi in the set S = {x1, x2, ..., xn}, from the pile. The last player
	to take out a coin is the winner. In wich positions does the first 
	player win? (in every turn each player plays optmally). 

	Let N be the number of coins in the pile.
	If N == 0, then the first player looses;
	If N is any number in the set S, the first player wins;
	If N minus a number from the S takes it to looser position, then
	the first player wins;
	Otherwise, it looses.

*/

bool isWinner[MAXN]; // Initialized with false
for (int i = 0; i < MAXN; i++){
	if (isWinner[i]) continue;

	for (auto x : s) // Every Xi in S
		isWinner[i+x] = true;
}

/*

	THE GAME OF NIM

	There are N piles with Mi coins in each. At each turn the player can
	take any amount of coins of ONE pile. When does the first player to
	play win?
	
	When m1 XOR m2 XOR ... XOR mn != 0, the first player wins, playing
	optmally.
*/

bool isNimWinner(int piles[], int n){
	int x = 0;
	for (int i = 0; i < n; i++)
		x ^= piles[i];

	return (x != 0);
}