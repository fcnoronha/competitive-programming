// https://www.urionlinejudge.com.br/judge/en/problems/view/2665

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)  for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()

#define gnl cout << endl
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int ori(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
 	return ((x2-x1)*(y3-y2) - (x3-x2)*(y2-y1));
}

int main(){
	int xa, xb, n, cont, ans, x, y;

	cin >> n >> xa >> xb;

	vii cord;
	vi insd(n+2, 0);

	fr (i, n){
		cin >> x >> y;
		cord.pb({y, x});
	}

	sort(cord.begin(), cord.end());

 	ans = 0;
	fr(i, n){
		cont = 0;

		for (int j = i-1; j >= 0; j--){
			if (ori(xa, 0, cord[i].snd, cord[i].fst, cord[j].snd, cord[j].fst) < 0 && ori(xb, 0, cord[i].snd, cord[i].fst, cord[j].snd, cord[j].fst) > 0){
				insd[i] = max(insd[i], insd[j]+1);
				cont++;
			} 
		}		
		
		if (cont == 0) insd[i] = 1;

		ans = max(ans, insd[i]);
	}

	cout << ans << endl; 

}