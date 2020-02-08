/*
	LINEAR RECURRENCE

	Solving problems with matrix exponenciation.
*/

/*
	Fibonacci O(logn)

	| F(n)	|	=	|1	1|n-2 * |1|
	| F(n-1)|		|1	0|		|1|

	The matrix with 1's and 0's is derived from the formula:
		F(n) = F(n-1) + F(n-2).
	So all the matrices has its sizes determined by the 
	number of terms thats its related polinomy has. 2, in
	Fiboncci's.

	OBS: The column of the second matrix multiply each line
	of the first matrix (the matrix with 0's and 1's).
*/

/*
	Another exemple

	Linear recurrence for the following polinomy
		F(i) = f(i-1) + 2f(i-2) + i² + i + 1

	| F(i)	|		|1	2	1	1	1|n-2	|f(i-1)|
	| F(i-1)|		|1	0	0	0	0|		|f(i-2)|
	| i²+2i+1|	=	|0	0	1	2	1|	*	|i²|
	| i+1	|		|0	0	0	1	1|		|i|
	| 1		|		|0	0	0	0	1|		|1|

*/

/*

	Travel in a graph

	Given a graph G and an vertice V, the task is to find
	the number of ways of getting into V, from any point in G, 
	with K steps.	

	Lets call this function F(v, k) and for the following sample
	our graph has 4 vertices. So, we have the following system:

	| F(1, k) |		|1	1	1	1|k		| F(1, 0) |
	| F(2, k) |		|1	0	0	0|		| F(2, 0) |
	| F(3, k) |	=	|0	0	1	2|	*	| F(3, 0) |
	| F(4, k) |		|0	0	0	1|		| F(4, 0) |

	and we know that F(v, 0) = 1, for any v in G.
	Also, our 1's and 0's matrix is the adjacency matrix, so,
	the first row says that the vertice 1 has edges connecting
	it to every other vertice(includig itself). In order to get
	the desired value, we just need to sum the v-th row.

	The last (rightest) matrix is aways formed by a base,
	already defined values.
*/