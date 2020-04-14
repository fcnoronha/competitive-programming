#include <bits/stdc++.h>
using namespace std;

const int N = 500001;
char s[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = i; j < n; j++) {
			if (s[j] != s[n - (j - i + 1)]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			int sum = i;
			for (int j = 0; j < i; j++) {
				s[n + sum - j - 1] = s[j];
			}
			s[n + sum] = '\0';
			printf("%s\n", s);
			return 0;
		}
	}

}