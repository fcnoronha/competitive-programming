#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))

#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]

#define f first
#define s second

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define MAXN 100009

int hi[4*MAXN + 1], lo[4*MAXN + 1], seg[4*MAXN + 1], v[MAXN + 1], lazy[4*MAXN + 1];

int update(int a, int b){
	return min(a, b);
}

int build(int node, int start, int end){
	//Start node value = 1
	lo[node] = start; hi[node] = end;

	if(start == end){
		return seg[node] = INF;
	}

	int mid = (end+start)/2;

	return seg[node] = update(build(2*node, start, mid), build(2*node + 1, mid + 1, end)); 
}



int query(int node, int start, int end){


	if(hi[node] < start || lo[node] > end) return INF;
	if(lo[node] >= start && hi[node] <= end){
		return seg[node];
	}

	return update(query(2*node, start, end), query(2*node + 1, start, end));

}

void change(int node, int start, int end, int x){


	if(hi[node] < start || lo[node] > end) return;
	if(lo[node] >= start && hi[node] <= end){
        seg[node] = x;
		return;
	}

	change(2*node, start, end, x);
	change(2*node+1, start, end, x);

	seg[node] = update(seg[2*node], seg[2*node+1]);
}

int main(){

    int t;
    cin >> t;

    while (t--) {


        int n;
        cin >> n;

        build(1, 1, n);

        pair<int, pii> oi[n];
        fr(i, n) 
            cin >> oi[i].f >> oi[i].s.f >> oi[i].s.s;
       

        sort(oi, oi+n);
        int ans = 0;

        fr(i, n) {
            int aux = query(1, 1, oi[i].s.f);
            if (aux > oi[i].s.s) 
                ans++;
            change(1, oi[i].s.f, oi[i].s.f, oi[i].s.s);
        }

        p(ans);
    }

}