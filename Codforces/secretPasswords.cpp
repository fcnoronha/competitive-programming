//codeforces.com/contest/1263/problem/D

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

int id[30], sz[30];

int find(int p){
    if (id[p] == p) return p;
    return id[p] = find(id[p]); 
}

void uni(int p, int q){
	p = find(p);
	q = find(q);

	if (p == q) return;
	if (sz[p] > sz[q]) swap(p, q);

	id[p] = q;
	sz[q] += sz[p];
}

int main(){
    fastio;

    fr(i, 27) id[i] = i, sz[i] = 1;

    int n;
    cin >> n;

    string s;
    map<char, bool> used;
    fr(i, n) {
        cin >> s;
        used[s[0]] = 1;
        fr(i, (int)s.size()-1) {
            uni(s[i]-97, s[i+1]-97); 
            used[s[i]] = used[s[i+1]] = 1;
        }
    }

    set<int> rep;
    for (auto x : used) {
        if (x.s == 0) continue;
        rep.insert(find(x.f-97));
        
    }

    p(rep.size());
}   
