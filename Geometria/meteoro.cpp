// https://br.spoj.com/problems/METEORO/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int x1, x2, y1, y2, n, ans, x, y, t = 0;

	while (cin >> x1 >> y1 >> x2 >> y2 && !(x1 == x2 && x2 == y1 && y1 == y2 && y2 == 0)){
		t++;
		ans = 0; n = 0;
		cin >> n;
		while (n--){
			cin >> x >> y;
			if (x >= x1 && x <= x2 && y <= y1 && y >= y2) ans++;
		}
		cout << "Teste " << t << endl << ans << endl << endl;
	}
}