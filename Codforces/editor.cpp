//codeforces.com/contest/1263/problem/E

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

#define MAXN 1000009

struct nd {
    int mn;
    int mx;
    int lazy;
} seg[(MAXN+10)*4];

int idx, n;

void unlazy(int node, int i, int j) {

    int left = 2*node;
	int right = 2*node + 1;
  
    int aux = seg[node].lazy;
    seg[node].lazy = 0;

    if (i == j) return;

    seg[right].mn += aux;
    seg[right].mx += aux;
    seg[right].lazy += aux;

    seg[left].mn += aux;
    seg[left].mx += aux;
    seg[left].lazy += aux;
}

void update(int node, int i, int j, int a, int b, int val){
    
    int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	if (i > j || i > b || a > j) return;

    unlazy(node, i, j);

	if (a <= i && j <= b){
		seg[node].lazy += val;
        seg[node].mn += val;
        seg[node].mx += val;
        return;
    }

    update(left, i, mid, a, b, val);
    update(right, mid+1, j, a, b, val);

    seg[node].mn = min(seg[left].mn, seg[right].mn);
    seg[node].mx = max(seg[left].mx, seg[right].mx);	
}

nd query(int node, int i, int j, int a, int b){

	int left = 2*node;
	int right = 2*node + 1;
	int mid = (i+j)/2;

	if (i > j || i > b || a > j) return {0, 0, 0};

    unlazy(node, i, j);

	if (a <= i && j <= b)
		return seg[node];

    nd l = query(left, i, mid, a, b);
    nd r = query(right, mid+1, j, a, b);
    
    nd ret;
    ret.mn = min(l.mn, r.mn);
    ret.mx = max(l.mx, r.mx);
    return ret;    
}

void res() {
    
    nd lst = query(1, 0, MAXN, MAXN, MAXN);
    nd td = query(1, 0, MAXN, 0, MAXN);
   
    if (lst.mx == 0 && td.mn >= 0) {
        printf("%d ", td.mx);
        return;
    }
    
    printf("-1 ");
}

int main(){

    cin >> n;

    string s;
    cin >> s;

    char pal[n];

    fr(i, n) {

        char c = s[i];

        if (c == 'R') {
            idx++;
            res();
            continue;
        }

        if (c == 'L') {
            idx = max(idx-1, 0);
            res();
            continue;
        }

        int val = 0;    
        if (pal[idx] == '(') val--;
        else if (pal[idx] == ')') val++;
        pal[idx] = c;
        
        if (c == '(') {
            val++;

            update(1, 0, MAXN, idx, MAXN, val);
            res();
            continue;
        }

        if (c == ')') {
            val--;

            update(1, 0, MAXN, idx, MAXN, val);
            res();
            continue;
        }

        update(1, 0, MAXN, idx, MAXN, val);
        res();
    }
    cout << endl;
}
