#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define ms(x, i)	memset(x, i, sizeof(x))

#define p(x) cout << #x << endl
#define pv(x) for (auto u : x) cout << u << " \n"[u == *(x.end()-1)];

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll segmin[400400],segmax[400400],segsum[400400];
ll v[100100];int n,q;

void build(int node, int l, int r){
	if(l==r){
		segmin[node]=segmax[node]=segsum[node]=v[l];
		return;
	}
	int mid = (l+r)>>1;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	segmin[node]=min(segmin[2*node],segmin[2*node+1]);
	segmax[node]=max(segmax[2*node],segmax[2*node+1]);
	segsum[node]=segsum[2*node]+segsum[2*node+1];
}

//op: 0=sum,1=min,2=max
ll query(int node, int l, int r, int a, int b, int op){

	if(l>b || r<a){
		if(op==0)	return 0;
		if(op==1)	return 0x3f3f3f3f;
		if(op==2)	return 0;
	}

	if(a<=l && r<=b){
		if(op==0)
			return segsum[node];
		if(op==1)
			return segmin[node];
		if(op==2)
			return segmax[node];
	}

	int mid = (l+r)>>1;

	ll lc = query(2*node,l,mid,a,b,op);
	ll rc = query(2*node+1,mid+1,r,a,b,op);

	if(op==0)
		return lc+rc;
	if(op==1)
		return min(lc,rc);
	if(op==2)
		return max(lc,rc);

}

void update(int node, int l, int r, int ind, int val){

	if(l==r){
		segsum[node]=segmin[node]=segmax[node]=val;
		return;
	}

	int mid = (l+r)>>1;

	if(ind<=mid)
		update(2*node,l,mid,ind,val);
	else
		update(2*node+1,mid+1,r,ind,val);

	segsum[node]=segsum[2*node]+segsum[2*node+1];
	segmin[node]=min(segmin[2*node],segmin[2*node+1]);
	segmax[node]=max(segmax[2*node],segmax[2*node+1]);

}

ll calc(int l, int r){
	ll sumquery = query(1,1,n,l,r,0);
	ll minquery = query(1,1,n,l,r,1);
	ll maxquery = query(1,1,n,l,r,2);
	return sumquery - minquery - maxquery;
}

int main(){

	fastio


	cin >> n >> q;

	frr(i,n)
		cin >> v[i];

	build(1,1,n);

	while(q--){
		int op;
		cin >> op;

		if(op==1){
			int l,r;
			cin >> l >> r;
			cout << calc(l,r) << endl;
		}
		else{
			ll ind,val;
			cin >> ind >> val;
			update(1,1,n,ind,val);
		}
	}

}
