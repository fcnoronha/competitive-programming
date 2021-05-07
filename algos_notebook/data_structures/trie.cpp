#include<bits/stdc++.h>
using namespace std;

// Store and check for strings

struct Trie {
    vector<bool> isEnd; // True if i-th node of trie is end of word
    vector<vector<int>> trie;
    int cnt = 1; // Latest node - trie[0] == root

    Trie(int _maxn): isEnd(_maxn, 0), trie(_maxn, vector<int>(26, -1)) {}

    void add(string str, int idx, int node){
        // If its already in the end
        if (str.length() == idx){
            isEnd[node] = true;
            return;
        }

        int &lidx = trie[node][ str[idx]-'a' ]; // Change for 0 if it's number
        // If there is no following to that letter
        if (lidx == -1)
            lidx = cnt++;

        add(str, idx+1, lidx);
    }

    bool search(string str, int idx, int node){
        // Found
        if (idx == str.length())
            return true;

        int &lidx = trie[node][ str[idx]-'a' ]; // Change for 0 if it's number
        // Not found
        if (lidx == -1)
            return false;

        return search(str, idx+1, lidx);
    }
};
    
int main(){

    int maxn = 10; // Number of words * Maximum length
    Trie trie(maxn);

    trie.add("felipe", 0, 0);
    cout << trie.search("k", 0, 0) << endl;

    // Consider using MAP[maxn] instead of trie[maxn][] if getting TLE
}