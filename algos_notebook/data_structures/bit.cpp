/*
    BINARY INDEXED TREE - FENWICK TREE

    Data structure that supoport range and update queries, both in O(logn).
    For [a, b] interval you have to do query(b) - query(a-1).
    Must be index from 1, in the form [1, maxn].
*/

int bit[maxn];

// [1, i] sum query
int query(int i){
    int sm = 0;
    for (; i > 0; i -= i&-i) sm += bit[i];
    return sm;
}

// sum x on position i
void update(int i, int x){
    for (; i <= maxn; i += i&-i) bit[i] += x;
}

