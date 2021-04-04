/*
    2 SAT
    O(n + m) - #variables + #clauses
*/

#define maxn 112345 // 2*(#MAXelements)

struct 2sat {

    int low[maxn], pre[maxn], id[maxn];
    int clk = 0, cnt = 0, numSCC = 0; // cnt == 2*(#elements) 
    bool eval[maxn];

    vector<int> adj[maxn];
    stack<int> nodes;

    void dfs(int v){
        nodes.push(v);
        pre[v] = low[v] = clk++;
        for (auto x: adj[v]) {
            if (pre[x] == -1) dfs(x);
            low[v] = min(low[v], low[x]);
        }
        if (low[v] == pre[v]) {
            while (1) {
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
            if (id[i] == id[neg(i)]) return 0;
            eval[i] = (id[i] < id[neg(i)]);
            eval[neg(i)] = !eval[i];
        }
        return 1;
    }
};

int main(){

    2sat sat;
    sat.cnt = 2*n; // set up
    ms(sat.pre, -1);

    // REMEMBER IT IS 1 INDEXED
}