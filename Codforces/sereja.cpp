// http://codeforces.com/contest/380/problem/C

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define priority_queue pq
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define dbg(x) cout << #x << " = " << x << endl

#define f first
#define s second

typedef long long int ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
typedef pair<ll,pii> no;

ll const maxn = 4*1000004;
string s;
ll comb[maxn], lf[maxn], rg[maxn], str[maxn], end[maxn], n, q;

void build(ll node, ll strb, ll endb){
	if (endb - strb < 2){
		if (s[strb] == '(') lf[node] = 1;
		else rg[node] = 1;
		return;
	}
	ll meio = (endb+strb)/2;
	build(2*node, strb, meio);
	build(2*node+1, meio, endb);

	ll aux = min(lf[node*2], rg[node*2+1]);
	comb[node] = comb[node*2] + comb[node*2+1] + aux;
	lf[node] = lf[node*2] + lf[node*2+1] - aux;
	rg[node] = rg[node*2] + rg[node*2+1] - aux;
	return;
}

no query(ll x, ll y, ll node, ll strq, ll endq){
    if(strq >= y || x >= endq) return no(0, pii(0,0));
    if(x <= strq && endq <= y) return no(comb[node], pii(lf[node], rg[node]));

    ll mid = (strq + endq)/2;
    no a = query(x, y, 2*node, strq, mid);
    no b = query(x, y, 2*node+1, mid, endq);

    ll COMB, LF, RG, aux;
    aux = min(a.s.f, b.s.s);
    COMB = a.f + b.f + aux;
    LF = a.s.f + b.s.f - aux;
    RG = a.s.s + b.s.s - aux;
    return no(COMB, pii(LF, RG));    
}


int main(){
	cin >> s;
	cin >> q;
	
	n = s.size();
	build(1, 0, n);

	fr(i, q){
		ll x, y;
		cin >> x >> y;
		no ans = query(x-1, y, 1, 0, n);
		cout << ans.f*2 << endl;
	}
}