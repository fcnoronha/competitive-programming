/*
    BINARY INDEXED TREE - 2D
    
To initialize it, just update every entry node
*/


struct Bit2d {
    vector<vector<int>> bit;
    int n;

    Bit2d(int _n): bit(_n, vector<int>(_n, 0)), n(_n) {} 

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
        for (int i = x; i < n; i += i&-i)
            for (int j = y; j < n; j += j&-j)
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