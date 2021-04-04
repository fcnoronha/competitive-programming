
// PALINDROMIC TREE
// Find all distinct palindromes substrings in O(n) 
// https://www.geeksforgeeks.org/palindromic-tree-introduction-implementation/

#define maxn 112345

struct PalTree
{
    struct Node {
        int start, end, length;
        int insert_edg[26], suffix_edg;
    };

    Node root1, root2, tree[maxn];
    int cur_node, ptr;
    string s;

    void init(string str) {
        root1.length = -1;
        root1.suffix_edg = 1;
        root2.length = 0;
        root2.suffix_edg = 1;
        tree[1] = root1;
        tree[2] = root2;
        ptr = 2;
        cur_node = 1;
        s = str;
        for (int i = 0; i < s.size(); i++) 
            insert(i);
    }

    void insert(int idx) {
        int tmp = cur_node;
        while (1) {
            int cur_length = tree[tmp].length;
            if (idx-cur_length >= 1 && s[idx] == s[idx-cur_length-1]) break;
            tmp = tree[tmp].suffix_edg;
        }
        if (tree[tmp].insert_edg[s[idx]-'a'] != 0) {
            cur_node = tree[tmp].insert_edg[s[idx]-'a'];
            return;
        }
        ptr++;
        tree[tmp].insert_edg[s[idx]-'a'] = ptr;
        tree[ptr].length = tree[tmp].length+2;
        tree[ptr].end = idx;
        tree[ptr].start = idx - tree[ptr].length+1;
        tmp = tree[tmp].suffix_edg;
        cur_node = ptr;
        if (tree[cur_node].length == 1) {
            tree[cur_node].suffix_edg = 2;
            return;
        }
        while (1) {
            int cur_length = tree[tmp].length;
            if (idx-cur_length >= 1 && s[idx] == s[idx-cur_length-1]) break;
            tmp = tree[tmp].suffix_edg;
        }
        tree[cur_node].suffix_edg = tree[tmp].insert_edg[s[idx] - 'a'];
    }

    // printing all of its distinct palindromic substrings
    void print_all() {
        for (int i = 3; i <= ptr; i++) {
            for (int j=tree[i].start; j <= tree[i].end; j++) cout << s[j]; 
            cout << endl; 
        }
    }
};

int main() {

    string str;
    cin >> str;

    PalTree tree;
    
    tree.init(str);
    tree.print_all();
}