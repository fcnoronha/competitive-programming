//onlinejudge.org/external/112/11294.pdf

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

#define maxn 5000 

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
    if (i < cnt/2) return i + cnt/2;
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
    
    fr(i, cnt) 
        if (pre[i] == -1) dfs(i);
    
    fr(i, cnt/2) {
        if (id[i] == id[neg(i)]) return false;
        eval[i] = (id[i] < id[neg(i)]);
        eval[neg(i)] = !eval[i];
    }

    return true;
}

int main(){


    int n, p;
    while (cin >> n >> p && n && p) {
        
        cnt = 4*n; 
        ms(pre, -1);
        fr(i, cnt) adj[i].clear();
        numSCC = 0, clk = 0;

        add_imp(neg(0), 0);
        fr(i, n) add_xor(i, i+n);

        while (p--) {

            string s1, s2;
            cin >> s1 >> s2;

            string aux1, aux2;
            fr(i, s1.size()-1) aux1.pb(s1[i]);
            fr(i, s2.size()-1) aux2.pb(s2[i]);

            int p1 = stoi(aux1);
            int p2 = stoi(aux2); 

            if (s1[s1.size()-1] == 'h') p1 += n;
            if (s2[s2.size()-1] == 'h') p2 += n;

            add_or(p1, p2);
        }

        if (!sat()) {
            p("bad luck");
            continue;
        }

        bool chato = 1;
        fr(i, cnt/2) {

            if (!i) continue;
            if (!eval[i]) continue;
            if (!chato) cout << " ";
            chato = 0;

            if (i < n) cout << i << "w";
            else cout << i-n << "h";
        } 
        cout << endl;   
    }
}
