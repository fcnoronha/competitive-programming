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
typedef vector<int> vi;

int const maxn = 200008;

int q, n, sum[maxn], slf[maxn], srg[maxn], v[maxn], srt_node[maxn], end_node[maxn];

int build(int node, int srt, int end){
	srt_node[node] = srt;
	end_node[node] = end;
	if (srt == end) return sum[node] = slf[node] = slf[node] = v[srt];

	int mid = (srt+end)/2;
	int_max[node] = max({build(2*node, srt, mid) + build(2*node+1, mid+1, end), 
		build(2*node+1, mid+1, end), build(2*node+1, mid+1, end)});
	return int_max[node];
}

int query(int node, int l, int r){
	if (end_node[node] < l || srt_node[node] > r) return -69696;
	else if (srt_node[node] >= l && end_node[node] <= r) return int_max[node];
	return max(query(node*2, l, r), query(node*2+1, l, r));
}

void update(int node, int i, int x){
	if (srt_node[node] > i || end_node[node] < i) return;
	else if (srt_node[node] == i && end_node[node] == i){
		v[i] = x;
		int_max[node] = x;
		return;
	}

	update(2*node, i, x);
	update(2*node+1, i, x);
	int_max[node] = max(int_max[2*node], int_max[2*node+1]);
}

int main(){	
	cin >> n;
	frr(i, n) cin >> v[i];

	fill(int_max, int_max+maxn, -69696);

	build(1, 0, n-1);

	cin >> q;
	fr(i, q){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 0) update(1, x, y);
		else cout << query(1, x, y) << endl;
	}		
}