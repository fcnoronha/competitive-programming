/*
	BINARY INDEXED TREE - 2D
	
To initialize it, just update every entry node
*/

#define maxn 10000

struct Bit2d {
	int bit[maxn][maxn];

	// Return the sum of the area delimited by x and y
	int sum(int x, int y){
		int ans = 0;
		for (int i = x; i > 0; i -= i&-i)
			for (int j = y; j > 0; j -= j&-j)
				ans += bit[i][j];
		return ans;
	}

	// Increase v in position {x,y}
	void update(int x, int y, int v){
		for (int i = x; i < maxn; i += i&-i)
			for (int j = y; j < maxn; j += j&-j)
				bit[i][j] += v;
	}
};

/*

 In order to calculate de sum of the area deliminited
 by the points (i,j) and (h,k), do as it follows:

 S = sum(h,k) - sum(h,j-1) - sum(i-1,k) + sum(i-1,j-1)

 Note that, here (h,k) is the bottom-right point and
 (i,j) is the upper-left one. 

*/