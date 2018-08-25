// https://br.spoj.com/problems/CERCAMG/

#include<bits/stdc++.h>
using namespace std;

int a, d, x, y;

int ori(pair<int,int> p, pair<int,int> q, pair<int,int> r){
	int val = (q.second - p.second)*(r.first - q.first) - 
			(q.first - p.first)*(r.second - q.second);
	if (val == 0) return 0;
	else if (val > 0) return 1;
	else return 2;
}

double dist(pair<int, int> a, pair<int, int> b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main(){
	while(scanf("	%d %d", &a, &d) != EOF){

		vector< pair<int,int> > point;
		for (int i = 0; i < a; i++){
			cin >> x >> y;
			point.push_back({x,y});
		}

		vector< pair<int,int> > hull;
		int l = 0;
		for (int i = 1; i < a; i++){
			if (point[i].first < point[l].first) l = i;
		}

		int p = l, q;
		do{
			hull.push_back(point[p]);
			q = (p+1)%a;
			for (int i = 0; i < a; i++)
				if (ori(point[p], point[i], point[q]) == 2)
					q = i;
			p = q;
		} while (p != l);

		double res = 0;
	    for (int i = 0; i <	 hull.size(); i++) {
	        res += dist(hull[i], hull[(i + 1) % a]);		
	    }
	    cout << fixed << setprecision(2) << res << endl;
	}
}