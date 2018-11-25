// https://codeforces.com/contest/1056/problem/C

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

typedef struct{
	int f, s, t;
}coiso;

bool comp(coiso a, coiso b){
	if (a.t != b.t)
		return a.t < b.t;
	else if (a.f != b.f)
		return a.f < b.f;
	return a.s <= b.s;
}

bool esc[20009];
vector<coiso> p;
ll adj[20009];

int main(){

	ll n, m;
	cin >> n >> m;

	frr(i, 2*n){
		ll a;
		cin >> a;
		p.pb({a, i, 0}); // {relação, poder, indice}
	}

	fr(i, m){
		ll a,b;
		cin >> a >> b;
		adj[a] = b;
		adj[b] = a;
		p[a-1].t = 1;
		p[b-1].t = 1;
	}

	ll atual = 0;
	sort(p.begin(), p.end(), comp);
	reverse(p.begin(), p.end());

	ll t;
	cin >> t;
	ll aux = 0;
	bool joguei = false;

	if(t == 1){
		while(n--){

			if (aux == -1) return 0;

			if (aux > 0){
				esc[aux] = true;
				ll u = adj[aux];
				
				if (!esc[u] && !joguei && u>0){
					esc[u] = true;
					joguei = true;
					cout << u << endl;
				}
				
			}

			if (!joguei){
				while(esc[p[atual].s]) atual++;
				esc[p[atual].s] = true;
				cout << p[atual].s << endl;
			}

			cin >> aux;			
			joguei = false;
		}
	}

	else{
		while(n--){

			cout.flush();
			cin >> aux;		

			if (aux == -1) return 0;

			if (aux > 0){
				esc[aux] = true;
				ll u = adj[aux];
			
				if (!esc[u] && !joguei && u > 0){
					esc[u] = true;
					joguei = true;
					cout << u << endl;
				}
				
			}

			if (!joguei){
				while(esc[p[atual].s]) atual++;
				esc[p[atual].s] = true;
				cout << p[atual].s << endl;
			}

			joguei = false;
		}
	}
	return 0;
}
