// http://codeforces.com/gym/100989/problem/H

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;	

int n, k, tro, f1, f2, f3, f4, f5, va, a, b, c, d, e;

int main(){
	cin >> n;

	bool res = true;

	fr(i, n){
		cin >> k >> f1 >> f2 >> f3 >> f4 >> f5;

		a += f1;
		b += f2;
		c += f3;
		d += f4;
		e += f5;

		va = 1*f1 + 5*f2 + 10*f3 + 20*f4 + 50*f5;

		tro = va - k;

		while(tro != 0){
			if(tro >= 50 and e > 0){
				tro -= 50;
				e --;
			}
			else if(tro >= 20 and d > 0){
				tro -= 20;
				d --;
			}
			else if(tro >= 10 and c > 0){
				tro -= 10;
				c --;
			}
			else if(tro >= 5 and b > 0){
				tro -= 5;
				b --;
			}
			else if(tro >= 1 and a > 0){
				tro -= 1;
				a --;
			}
			else if(tro >= 1 and a == 0){
				res = false;
				break;
			}
		}
	}

	if(res == true) cout << "yes" << endl;
	else cout << "no" << endl;
}

