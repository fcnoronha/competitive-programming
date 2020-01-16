//codeforces.com/contest/1288/problem/E

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

#define maxn 600009

int bit[maxn];

int query(int i){
	int sum = 0;
    for (; i > 0; i -= i&-i)
    	sum += bit[i];
    return sum;
}

void update(int x, int i){
	for (; i <= maxn; i += i&-i)
		bit[i] += x;
}

int main(){
    //fastio;

    int n;
    cin >> n;

    pii ans[n];
    int p = maxn-3, pos[n];

    for (int i = n; i > 0; i--) {

        pos[i] = p;
        update(1, p);
        ans[i] = {i,i};

        p--;
    }

    int q;
    cin >> q;

    while (q--) {

        int x;
        cin >> x;

        ans[x].f = 1;

        ans[x].s = max(ans[x].s, query(pos[x]));

        update(-1, pos[x]);
        pos[x] = p--;
        update(1, pos[x]);
    }

    frr(i, n) 
        ans[i].s = max(ans[i].s, query(pos[i]));
    
    frr(i, n) cout << ans[i].f << " " << ans[i].s << endl;
}
