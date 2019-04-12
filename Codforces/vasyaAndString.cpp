// codeforces.com/contest/676/problem/C

#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;

int check(char x) {

	// Valor de retorno, ponteiro left e right
	int ret = 0, l, r = 0;

	// Quantos caracteres 'x' ja passei por
	int cnt = 0;

	// Pointer da esquerda esta dentro da string
	for (l = 0; l < n; l++) {

		while (r < n && (cnt < k || s[r] != x)) {

			if (s[r] == x)
				cnt++;

			r++;
		}

		if (s[l] == x)
			cnt--;

		if (ret < r-l)
			ret = r-l;
	}

	return ret;

}

int main(){

	cin >> n >> k;
	cin >> s;

	int ansa = check('a');
	int ansb = check('b');
	int ans;

	if (ansa > ansb)
		ans = ansa;

	else
		ans = ansb;

	cout << ans << endl;
}
