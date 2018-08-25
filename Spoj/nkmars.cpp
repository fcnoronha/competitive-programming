// https://www.spoj.com/problems/NKMARS/

#include<bits/stdc++.h>
using namespace std;


int main(){
	int n, x1, y1, x2, y2, cont_v, delta, hgt, ans;
	cin >> n;

	pair<int,int> xs[(n*2)+2], ys[(n*2)+2];
	bool h[(n*2)+2], v[(n*2)+2];

	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		xs[2*i] = make_pair(x1, i);
		xs[2*i + 1] = make_pair(x2, i);
		ys[2*i] = make_pair(y1, i);
		ys[2*i + 1] = make_pair(y2, i);
	}
	sort(xs, xs+2*n);
	sort(ys, ys+2*n);
	ans = 0;
	fill(h, h+n, false);

	for (int i = 0; i < 2*n ; i++) {
		h[xs[i].second] = !h[xs[i].second];
		if (i > 0) ans += (xs[i].first - xs[i-1].first) * hgt;
		hgt = 0;
		fill(v, v+n, false);
		for (int j = 0; j < n*2; j++) {
			if (h[ys[j].second]) {
				v[ys[j].second] = !v[ys[j].second];
				if (v[ys[j].second]) cont_v++; else cont_v--;
				if (v[ys[j].second] && cont_v == 1) delta = ys[j].first;
				else if (!v[ys[j].second] && cont_v == 0) hgt += ys[j].first - delta;
			}
		}
	}

	cout << ans << endl;
}

