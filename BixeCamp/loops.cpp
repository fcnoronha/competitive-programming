#include <iostream>
using namespace std;

/* team training
int main() {
	int m, n, r = 0, x = 1, r2 = 0;
	cin >> n >> m;
	// n = veteranos e m = novatos

	while (x != 0) {
		if ((n - 1 >= 0) && (m - 2 >= 0)) {
			n = n - 1;
			m = m - 2;
			r += 1;
		} else {
			if ((n - 2 >= 0) && (m - 1 >= 0)) {
				n = n - 2;
				m = m - 1;
				r += 1;
			}
			x = 0;
		}
	}

	x = 1;

	while (x != 0) {
		if ((n - 2 >= 0) && (m - 1 >= 0)) {
			n = n - 2;
			m = m - 1;
			r2 += 1;
		} else {
			if ((n - 1 >= 0) && (m - 2 >= 0)) {
				n = n - 1;
				m = m - 2;
				r2 += 1;
			}
			x = 0;
		}
	}

	cout << max(r, r2) << endl;
}
*/

/* lucky number

int main() {
	string numero, qtd;
	int n = 0, r = 0;
	cin >> numero;
	for (int x = 0; x < numero.length(); x++) {
		if (numero[x] == '4' || numero[x] == '7') {
			n++;
		}
	}

	qtd = to_string(n);
	for (int x = 0; x < qtd.length(); x++) {
		if (qtd[x] == '4' || qtd[x] == '7') {
			r++;
		}
	}

	if (r == qtd.length()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
*/

/* permutation 1
int main() {
	int t, p = 0, n1, n2;
	cin >> t;

	for (int x = 0; x < t; x++) {
		cin >> p;
		if (p % 2 == 1 || p < 0) {
			cout << "-1" << endl;
		}
		else {
			n1 = 0;
			n2 = 0;
			for (int y = 0; y < p; y++) {
				if (y % 2 == 0) {
				  n1 = n1 + 2;
					cout << n1 << " ";
				}
				else if (y % 2 == 1) {
				  n2 = n1 - 1;
					cout << n2 << " ";
				}
			}
			cout << endl;
		}
	}
}
*/

int main() {
	int n, a, b, c, d, e, f, r = 0, r0 = 0, x;
	cin >> n >> a >> b >> c;

	d = min(min(a, b), c);
	f = max(c, max(a,b));
	e = (a + b + c) - (d + f);

	
	while (n > 0) {
		if (n - d >= 0) {
			n = n - d;
			r++;
			if (n % d == 0 && n - d >= 0) {
				n = n - d;
				r++;
			} else if (n % e == 0 && n - e >= 0) {
				n = n - e;
				r++;
			} else if (n % f == 0 && n - f >= 0) {
				n = n - f;
				r++;
			}
		}
		else {
		  break;
		}
	}

	if (r > r0 && n == 0) {
		r0 = r;
	}

	
	while (n > 0) {
		if (n - e >= 0) {
			n = n - e;
			r++;
			if (n % d == 0 && n - d >= 0) {
				n = n - d;
				r++;
			} else if (n % e == 0 && n - e >= 0) {
				n = n - e;
				r++;
			} else if (n % f == 0 && n - f >= 0) {
				n = n - f;
				r++;
			}
		}
		else {
		  break;
		}
	}

	if (r > r0 && n == 0) {
		r0 = r;
	}

	
	while (n > 0) {
		if (n - f >= 0) {
			n = n - f;
			r++;
			if (n % d == 0 && n - d >= 0) {
				n = n - d;
				r++;
			} else if (n % e == 0 && n - e >= 0) {
				n = n - e;
				r++;
			} else if (n % f == 0 && n - f >= 0) {
				n = n - f;
				r++;
			}

		}
		else {
		  break;
		}
	}

	if (r > r0 && n == 0) {
		r0 = r;
	}

	cout << r0 << endl;
}

//ver pq esse ta falhando qd 10 5 5 5 