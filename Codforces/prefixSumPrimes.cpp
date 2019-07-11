//codeforces.com/contest/1150/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << endl
#define pv(x) for (auto u : x) cout << u << " "; cout << "\n";

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define maxn 200009

vector<int> isPrime(maxn, true);
vector<int> prime;
vector<int> SPF(maxn);

void seive(int n)
{
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < n; i++){
		if (isPrime[i]){
			prime.push_back(i);
			SPF[i] = i;
		}

		for (int j = 0;
			j < (int)prime.size() &&
			i*prime[j] < n && prime[j] <= SPF[i];
			j++)
		{
			isPrime[i*prime[j]] = false;
			SPF[i*prime[j]] = prime[j] ;
		}
	}
}

int n, n1, n2;

int main(){
	fastio

	cin >> n;

	int aux;
	fr(i, n) {
		cin >> aux;

		n1 += aux == 1;
		n2 += aux == 2;
	}

	seive(maxn);
	reverse(all(prime));

	int ac = 0;
	while (n1 || n2) {

		int next_p = prime.back();
		if (next_p == ac + 1 && n1) {
			ac++;
			n1--;
			cout << "1 ";
			prime.pop_back();
		}

		else if (next_p == ac + 2 && n2) {
			ac += 2;
			n2--;
			cout << "2 ";
			prime.pop_back();
		}

		else {
			if (n2) {
				ac += 2;
				n2--;
				cout << "2 ";
			}

			else if (n1) {

				ac += 1;
				n1--;
				cout << "1 ";
			}

			else {
				break;
			}
		}

		if (ac >= prime.back())
			prime.pop_back();
	}

	cout << endl;
}
