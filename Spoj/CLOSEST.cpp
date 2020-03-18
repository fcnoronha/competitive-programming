//www.spoj.com/problems/CLOSEST/

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


struct pt {
    ll x, y;
};

int n; 
double min_dist;
vector<pt> a, aux;

bool cmp_x(pt &a, pt &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_y(pt &a, pt &b) {
    return a.y < b.y;
}

void upd_ans(pt &a, pt &b, pt &c) {

    ll d1 = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    ll d2 = (a.x-c.x)*(a.x-c.x) + (a.y-c.y)*(a.y-c.y);
    ll d3 = (c.x-b.x)*(c.x-b.x) + (c.y-b.y)*(c.y-b.y);
    double dist = sqrt(d1) + sqrt(d2) + sqrt(d3);
    if (dist < min_dist) 
        min_dist = dist;
}

void solve(int l, int r) {
    if (r-l <= 3) {
        for (int i = l; i < r; i++) 
            for (int j = i+1; j < r; j++) 
                for (int k = j+1; k < r; k++)
                    upd_ans(a[i], a[j], a[k]);
        sort(a.begin()+l, a.begin()+r, cmp_y);
        return;
    }

    int m = (l+r)/2;
    long long int midx = a[m].x;
    solve(l, m);
    solve(m, r);

    merge(a.begin()+l, a.begin()+m, a.begin()+m, a.begin()+r, aux.begin(), cmp_y);
    copy(aux.begin(), aux.begin()+r-l, a.begin()+l);

    int aux_sz = 0;
    for (int i = l; i < r; i++) {
        if ((a[i].x-midx) < min_dist) {
            for (int j = aux_sz-1; j >= max(0, aux_sz-7); j--) 
                for (int k = j-1; k >= max(0, j-7); k--)
                    upd_ans(a[i], aux[j], aux[k]);
            aux[aux_sz++] = a[i];
        }
    }
}

int main() {
    fastio;
    cout << setprecision(3) << fixed;

    while (cin >> n && n != -1) {
    
        aux.clear(); a.clear();
        aux.resize(n); a.resize(n);

        fr(i, n) cin >> a[i].x >> a[i].y;
        sort(a.begin(), a.end(), cmp_x);

        min_dist = 10E20;
        solve(0, n);
        p(min_dist);
    }
}
