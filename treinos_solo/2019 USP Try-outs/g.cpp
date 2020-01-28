//codeforces.com/gym/102299

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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

#define maxn 100009
int id[maxn], sz[maxn], mn[maxn];

int find(int p){

    if (id[p] == p) return p;

    int x = find(id[p]);
    mn[p] = min(mn[p], mn[id[p]]);

    return id[p] = x;
}

void uni(int i, int j){

	if (i == j) return;
    mn[j] = min(mn[id[j]], mn[j]);
	id[j] = i;
    mn[j] = min(mn[i], mn[j]);
}

int main(){
    fastio

    int n, q;
    cin >> n >> q;

    frr(i, n) id[i] = i, sz[i] = 1;
    frr(i, n) cin >> mn[i];

    while (q--) {
        string op;
        cin >> op;

        if (op == "+") {
            int i, j;
            cin >> i >> j;

            uni(i, j);
        }

        else {
            int x;
            cin >> x;

            find(x);
            p(mn[x]);
        }
    }
}
