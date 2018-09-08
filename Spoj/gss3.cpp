// https://www.spoj.com/problems/GSS3/

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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int const maxn = 50002;

struct node {
	pll sum, presum, sufsum, maxsum;
};

node tree[maxn * 4];

ll val[maxn];

pll sum(pll a, pll b){
	pll r;
	r.f = a.f + b.f;
	r.s = a.s + b.s;
	return r;
}


void build(int index, int left, int right){
	if (left == right){
		tree[index].sum.f = val[right];
		tree[index].sum.s = 1;
		tree[index].maxsum.f = val[right];
		tree[index].maxsum.s = 1;
		tree[index].presum.f = val[right];
		tree[index].presum.s = 1;
		tree[index].sufsum.f = val[right];
		tree[index].sufsum.s = 1;
		//dbg(val[right]);
	}
	else {
		int mid = (left+right)/2;

		build(2*index, left, mid);
		build(2*index + 1, mid+1, right);

		tree[index].sum = sum(tree[2*index].sum, tree[2*index+1].sum);

		//dbg(index);
		//dbg(tree[2*index].presum.f);
		//dbg(sum(tree[2*index].sum, tree[2*index+1].presum).f);
		tree[index].presum = max(tree[2*index].presum, 
			sum(tree[2*index].sum, tree[2*index+1].presum));

		tree[index].sufsum = max(tree[2*index+1].sufsum, 
			sum(tree[2*index+1].sum, tree[2*index].sufsum));	

		tree[index].maxsum = max({tree[index].sufsum, tree[index].presum,
			tree[2*index].maxsum, tree[2*index+1].maxsum, 
			sum(tree[2*index].sufsum, tree[2*index+1].presum)});

		//cout << tree[index].presum.f << endl;
	}
}

void update(int index, int left, int right, int index_updt, int value){
	if (left == right){
		tree[index].sum.f = value;
		tree[index].maxsum.f = value;
		tree[index].presum.f = value;
		tree[index].sufsum.f = value;
	}
	else {
		int mid = (left+right)/2;

		if (index_updt <= mid)
			update(2*index, left, mid, index_updt, value);

		else
			update(2*index+1, mid+1, right, index_updt, value);

		tree[index].sum = sum(tree[2*index].sum, tree[2*index+1].sum);

		tree[index].presum = max(tree[2*index].presum, 
			sum(tree[2*index].sum, tree[2*index+1].presum));

		tree[index].sufsum = max(tree[2*index+1].sufsum, 
			sum(tree[2*index+1].sum, tree[2*index].sufsum));

		tree[index].maxsum = max({tree[index].sufsum, tree[index].presum,
			tree[2*index].maxsum, tree[2*index+1].maxsum, 
			sum(tree[2*index].sufsum, tree[2*index+1].presum)});
	}
}

node query(int index, int left, int right, int qleft, int qright){

	node ans;
	ans.sum = ans.presum = ans.sufsum = ans.maxsum = {-500000000, -5000000};

	if (qright < left || right < qleft) return ans;

	if (qleft <= left && qright >= right) return tree[index];

	int mid = (left+right)/2;

	if (left > mid) 
		return query(2*index+1, mid+1, right, qleft, qright);

	if (right <= mid)
		return query(2*index, left, mid, qleft, qright);

	node l = query(2*index, left, mid, qleft, qright);
	node r = query(2*index+1, mid+1, right, qleft, qright);

	ans.sum = sum(l.sum, r.sum);
	ans.presum = max(l.presum, sum(l.sum, r.presum));
	ans.sufsum = max(r.sufsum, sum(r.sum, l.sufsum));
	ans.maxsum = max({ans.presum, ans.sufsum, l.maxsum,
		r.maxsum, sum(l.sufsum, r.presum)});

	return ans; 
}

int main(){	
	int n, q;

	cin >> n;
	fr(i, n) cin >> val[i];

	fr(i, 4*maxn){
		tree[i].sum = tree[i].presum = tree[i].sufsum = tree[i].maxsum = {-500000000, -5000000};
	}

	build(1, 0, n-1);

	cin >> q;
	fr(i, q){
		ll t, x, y;
		cin >> t >> x >> y;
		if (t == 0){
			val[x-1] = y;
			update(1, 0, n-1, x-1, y);
		}
		else{
			node res = query(1, 0, n-1, x-1, y-1);
			cout << res.maxsum.f << endl;
		}
	}		
}