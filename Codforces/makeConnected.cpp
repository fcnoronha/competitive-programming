// https://codeforces.com/contest/1095/problem/F

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

typedef struct aresta{
    ll dis;
    ll u, v;
} aresta;

bool comp(aresta a, aresta b){ 
	return a.dis < b.dis; 
}

ll id[300009], sz[300009];

int find(ll x){
    if(id[x] == x) return x;
    return id[x] = find(id[x]);
}

void join(ll a, ll b){    
    a = find(a);
    b = find(b);
    
    if (sz[a] < sz[b]) id[a] = b;
    else if (sz[b] < sz[a]) id[b] = a;
    else {
        id[a] = b;
        sz[b]++;
    }    
}

int main(){
	fastio
	
	ll n, m;
	cin >> n >> m;

	ll a[n+1], mn = LLONG_MAX, mni;
	frr(i, n){
		cin >> a[i];
		if (a[i] < mn){
			mni = i;
			mn = a[i];
		}
	}

	vector<aresta> v;

	frr(i,n){
		if (i == mni) continue;
		v.pb({a[mni]+a[i], mni, i});
	}

	fr(i, m){
		ll a, b, c;
		cin >> a >> b >> c;
		v.pb({c, a, b});
	}

	sort(v.begin(), v.end(), comp);

	// fr(i,v.size()) dbg(v[i].dis), dbg(v[i].u), dbg(v[i].v), cout << endl;

	frr(i, n) id[i] = i, sz[i] = 1;

	ll ans = 0;
	fr(i, v.size()){
		if (find(v[i].u) != find(v[i].v)){
			join(v[i].u, v[i].v);
			ans += v[i].dis;
		}
	}

	cout << ans << endl;
}
