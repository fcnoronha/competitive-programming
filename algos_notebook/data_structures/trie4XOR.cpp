// Usage of trie to do XOR stuff

/*
    At this problem the user can add one number to the set, with + op;
    It also can delete one number from the set, whith - op;
    And finally, it can give me a number X and ask me to find one number
    S in the set such as the operation X^S (XOR) is the biggest possible
    among all elements in the set.
*/

#define maxn 7000009 // N * log2(max_val)

struct Trie4XOR {
    vector<vector<int>> trie;
    vector<int> amt, val;
    int cnt = 1; 

    Trie4XOR(int _maxn): trie(_maxn, vector<int>(2, 0)), amt(_maxn, 0), val(_maxn, 0) {}

    // Add str (binary rep) to the tree, and increment 1 in each node
    // Store value V of that binary rep in the last node
    void add(string &str, int idx, int node, int v) {
        amt[node]++;
        if (idx == str.length()) {
            val[node] = v;
            return;
        }
        int &lidx = trie[node][ str[idx]-'0' ];
        if (lidx == -1) {
            lidx = cnt++;
            trie[lidx][0] = trie[lidx][1] = -1;
        }

        add(str, idx+1, lidx, v);
    }

    // Return biggest possible value for me to do an XOR operation
    int search(string str, int idx, int node) {
        if (idx == str.length())
            return val[node];
        
        int aux = ((str[idx]-'0')+1)%2; 
        int &lidx = trie[node][aux];
        if (amt[lidx] > 0)
            return search(str, idx+1, lidx);

        aux = (aux+1)%2;
        return search(str, idx+1, trie[node][aux]);
    }

    // Descrease 1 in each node of the value represented by str
    void del(string str, int idx, int node) {
        amt[node]--;

        if (idx == str.length())
            return;
        int &lidx = trie[node][ str[idx]-'0' ];
        del(str, idx+1, lidx);
    }
};
int main(){

    int q; cin >> q;

    Trie4XOR trie(maxn);
    trie.trie[0][0] = trie.trie[0][1] = -1;

    // Getting binary representation of an interger
    // 30 is the size of myy representation
    bitset<30> z(0);
    string zero = z.to_string();
    trie.add(zero, 0, 0, 0);

    while (q--){

        char op;
        int x;

        cin >> op >> x;

        bitset<30> bt(x);
        string str = bt.to_string();

        if (op == '+') tree.add(str, 0, 0, x);
        else if (op == '-') tree.del(str, 0, 0);
        else {
            int s = tree.search(str, 0, 0);
            cout << (s^x) << endl;
        }
    }
}
