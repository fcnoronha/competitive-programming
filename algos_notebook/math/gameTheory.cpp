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

/*

	The Grundy number consists of the MEX of the states that a certain 
	state can reach. For example, lets suppose that in a state S we can 
	reach the following states: {1,2,4,6}, the Grundy number of S is 0, 
	if the set of reacheble states were {0,1,2,4,6}, them the Grundy of 
	S should be 3.
	If a game is a NIM derivative, we can let X be the XOR's operations 
	between all Grundy numbers in that game, if X is a nonzero number, 
	the first player wins.

	A very good example of this way of thinking is my solution for the 
	problem Marbles, available in the following link:
	https://codeforces.com/gym/101908/submission/49813854

	Now it's easy to see why we make XOR operations with the size of 
	the piles in NIM game to see who is going to win, because the MEX 
	of a pile with size N is N, hence we can take any quantity X, X > 0, 
	from the pile.

*/