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

#define maxn 100009
#define lst 200009
int seg[2*maxn][9];
int lzy[maxn];
int n, h, q;

void merge(int pa, int pb, int pc) {
    int *a = seg[pa];
    int *b = seg[pb];
    int *c = seg[pc];
    fr(i, 9) 
        c[i] = a[i]+b[i];
}

void rotate(int pa, int val) {
    int *a = seg[pa];
    int *b = seg[lst];
    fr(i, 9) 
        b[ (i+val)%9 ] = a[i];
    fr(i, 9) 
        a[i] = b[i];
}

int max_freq(int pa) {
    int ans = 0, *a = seg[pa];
    frr(i, 8) 
        if (a[i] >= a[ans])
            ans = i;
    return ans;
}

void apply(int p, int val) {
    rotate(p, val);
    if (p < n) lzy[p] += val;
}

// update parents
void build(int p) {
    while (p > 1) {
        p >>= 1;
        merge(p<<1, p<<1|1, p);
        rotate(p, lzy[p]); 
    }
}

// propagate changes from root to p
void push(int p) {
    for (int s = h; s > 0; s--) {
        int i = p>>s;
        if (lzy[i]) {
            apply(i<<1, lzy[i]);
            apply(i<<1|1, lzy[i]);
            lzy[i] = 0;
        }
    }
}

void update(int l, int r, int val) {
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l>>=1, r>>=1) {
        if (l&1) apply(l++, val);
        if (r&1) apply(--r, val);
    }
    build(l0);
    build(r0-1);
}

int query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r-1);
    fr(i, 9) seg[lst][i] = 0;
    for (; l < r; l>>=1, r>>=1) {
        if (l&1) merge(lst, l++, lst);
        if (r&1) merge(lst, --r, lst);
    }
    return max_freq(lst);
}

void dbgt() {
    frr(i, n+n-1) {
        cout << i << ": ";
        fr(j, 9) cout << seg[i][j] << " ";
        cout << endl;
    } 
}

void print_ans() {
    fr(i, n) 
        p(query(i, i+1));
}

int main(){
    fastio;

    cin >> n >> q;
    h = 32 - __builtin_clz(n);

    fr(i, n) seg[i+n][1] = 1;
    for (int i = n-1; i > 0; i--) 
        merge(i<<1, i<<1|1, i);

    while (q--) {

        int a, b, f;
        cin >> a >> b;
        b++;
        f = query(a, b);
        update(a, b, f);
    }

    print_ans();
}
