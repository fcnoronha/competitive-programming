// http://www.codcad.com/problem/121

#include <bits/stdc++.h>
using namespace std;

int n, grid[101][101], dist[101][101];
int inf = INT_MAX;

int main(){
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];

			dist[i][j] = inf;
		}
	}

	set<pair<int,int> > q;

	q.insert(make_pair(0,0));
	dist[0][0] = 0;

 	int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while(!q.empty()){
    	pair<int,int> p = *q.begin();
    	q.erase(q.begin());


    	for (int i = 0; i < 4; i++){
            int x = p.first + dx[i];
            int y = p.second + dy[i];

            if(!((x >= 0 && x < n) && (y >= 0 && y < n))) continue;

            //cout << "x: " << x << "  y: " << y << endl;
            if (dist[x][y] > dist[p.first][p.second] + grid[x][y])
            {
                //if (dist[x][y] != inf)
                //    q.erase(q.find(make_pair(x,y)));

                dist[x][y] = dist[p.first][p.second] + grid[x][y];
                q.insert(make_pair(x,y));
            }
        }
    }

	cout << dist[n-1][n-1] << endl;
}