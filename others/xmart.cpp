//www.urionlinejudge.com.br/judge/en/problems/view/1348

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

#define maxn 30000

int low[maxn], pre[maxn], id[maxn];
int clk = 0, cnt = 0, numSCC = 0; 
bool eval[maxn];

vector<int> adj[maxn];
stack<int> nodes;

void dfs(int v){

    nodes.push(v);
    pre[v] = low[v] = clk++;;

    for (auto x: adj[v]) {
        if (pre[x] == -1) dfs(x);
        low[v] = min(low[v], low[x]);
    }

    if (low[v] == pre[v]) {
        while (true) {
            int j = nodes.top();
            nodes.pop();
            id[j] = numSCC;
            low[j] = INF;
            if (j == v) break;
        }
        numSCC++;
    }
}

int neg(int i) {
    if (i <= cnt/2) return i + cnt/2;
    return i - cnt/2; 
}

void add_imp(int i, int j) {
    adj[i].pb(j);
}

void add_or(int i, int j) {
    add_imp(neg(i), j);
    add_imp(neg(j), i);
}

void add_xor(int i, int j) {
    add_or(i, j);
    add_or(neg(i), neg(j));
}

void force_var(int i) {
    add_imp(neg(i), i);
}

bool sat() {
    
    for (int i = 1; i <= cnt; i++)
        if (pre[i] == -1) dfs(i);
    
    for (int i = 1; i <= cnt/2; i++) {
        if (id[i] == id[neg(i)]) return false;
        eval[i] = (id[i] < id[neg(i)]);
        eval[neg(i)] = !eval[i];
    }

    return true;
}

int main(){
    fastio;

    int c, p;
    ms(pre, -1);
    while (cin >> c >> p && c && p) {

        cnt = 2*p;

        fr(i, c) {

            int a, b;
            cin >> a >> b;
            if (a == 0) a = b;
            if (b == 0) b = a;
            if (a && b) add_or(a, b);

            cin >> a >> b;
            if (a == 0) a = b;
            if (b == 0) b = a;
            if (a && b) add_or(neg(a), neg(b));
        }

        if (sat()) p("yes");
        else p("no");

        fr(i, p*3) adj[i].clear();
        while (nodes.size()) nodes.pop();
        ms(pre, -1);
    }
}
