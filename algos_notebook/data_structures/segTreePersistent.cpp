
// PERSISTENT SEGMENT TREE

#define maxn 100

struct SegTreePersistent
{
    struct node  {
        // stores sum of the elements in node
        int val;
        node* left, *right;

        node() {}
        node(node* l, node* r, int v) {
            left = l;
            right = r;
            val = v;
        }
    };

    int arr[maxn]; // input array
    node* version[maxn]; // root pointers for all versions

    // Constructs Version-0, O(nlogn)
    void build(node* n,int low,int high) {
        if (low==high) {
            n->val = arr[low];
            return;
        }
        int mid = (low+high) / 2;
        n->left = new node(NULL, NULL, 0);
        n->right = new node(NULL, NULL, 0);
        build(n->left, low, mid);
        build(n->right, mid+1, high);
        n->val = n->left->val + n->right->val;
    }


    // Upgrades to new Version O(logn)
    void upgrade(node* prev, node* cur, int low, int high, int idx, int value) {
        if (idx > high || idx < low || low > high)
            return;

        if (low == high) {
            cur->val = value;
            return;
        }
        int mid = (low+high) / 2;
        if (idx <= mid) {
            cur->right = prev->right; // right child of previous version
            cur->left = new node(NULL, NULL, 0); //  new node in current version
            upgrade(prev->left,cur->left, low, mid, idx, value);
        }
        else {
            cur->left = prev->left; // left child of previous version
            cur->right = new node(NULL, NULL, 0);//  new node in current version
            upgrade(prev->right, cur->right, mid+1, high, idx, value);
        }
        cur->val = cur->left->val + cur->right->val; // data for current version
    }

    int query(node* n, int low, int high, int l, int r)
    {
        if (l > high or r < low or low > high)
        return 0;
        if (l <= low and high <= r)
        return n->val;
        int mid = (low+high) / 2;
        int p1 = query(n->left,low,mid,l,r);
        int p2 = query(n->right,mid+1,high,l,r);
        return p1+p2;
    }
};

int main() {
    int A[] = {1,2,3,4,5};
    int n = 5

    SegTreePersistent tree;
    for (int i=0; i<n; i++)
       tree.arr[i] = A[i];

    // creating Version-0
    node* root = new node(NULL, NULL, 0);
    tree.build(root, 0, n-1);
    // storing root node for version-0
    tree.version[0] = root;
    // upgrading to version-1
    tree.version[1] = new node(NULL, NULL, 0);
    tree.upgrade(version[0], version[1], 0, n-1, 4, 1);
    // upgrading to version-2
    tree.version[2] = new node(NULL, NULL, 0);
    tree.upgrade(version[1],version[2], 0, n-1, 2, 10);
    cout << "In version 1 , query(0,4) : ";
    cout << tree.query(version[1], 0, n-1, 0, 4) << endl;
    cout << "In version 2 , query(3,4) : ";
    cout << tree.query(version[2], 0, n-1, 3, 4) << endl;
    cout << "In version 0 , query(0,3) : ";
    cout << tree.query(version[0], 0, n-1, 0, 3) << endl;
    return 0;
}

/*
In version 1 , query(0,4) : 11
In version 2 , query(3,4) : 5
In version 0 , query(0,3) : 10
*/
