#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.end(),x.end()
#define ms(x, i) memset(x, i, sizeof(x))
#define p(x) cout << x << "\n"
#define pv(x) fr(i, x.size()) cout << x[i] << " \n"[i==x.size()-1]
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int ans = 1;

struct palindromic_tree {

    struct node {
        int length, link, end;
        map<char, int> to;
        
        node(int _length, int _link, int _end): 
            length(_length), link(_link), end(_end) {}
    };

    vector<node> nodes;
    int current;
    string s;
    
    palindromic_tree(string &_s): current(1), s(_s) {
        nodes.push_back(node(-1, 0, 0));
        nodes.push_back(node(0, 0, 0));

        for (int i = 0; i < int(s.size()); i++) add(i);
    }
    
    void add(int i) {
        
        int parent = nodes[current].length == i 
            ? nodes[current].link 
            : current;

        while (s[i - nodes[parent].length - 1] != s[i])
            parent = nodes[parent].link;

        if (nodes[parent].to.find(s[i]) != nodes[parent].to.end()) {
            current = nodes[parent].to[s[i]];
            return;
        } 

        int link = nodes[parent].link;
        while (s[i - nodes[link].length - 1] != s[i])
            link = nodes[link].link;
        
        link = max(1, nodes[link].to[s[i]]);
        current = nodes[parent].to[s[i]] = nodes.size();
        nodes.push_back(node(nodes[parent].length + 2, link, i));
        ans = max(ans, nodes[parent].length + 2);
    }

    void print_all_distinct_palindromes() {
        for (int i = 2; i <= current; i++) {
            for (int j = nodes[i].end - nodes[i].length + 1; j <= nodes[i].end; j++)
                cout << s[j];
            cout << endl;
        }
    }

};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    int n; cin >> n;
    string s; cin >> s;

    palindromic_tree t(s);

    p(ans);
}