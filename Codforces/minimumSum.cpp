//codeforces.com/contest/120/problem/J

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
    int id, k;
};

int n;
ll min_dist2;
pair<pt, pt> best_pair;
vector<pt> a, aux;

bool cmp_x(pt &a, pt &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_y(pt &a, pt &b) {
    return a.y < b.y;
}

void upd_ans(pt &a, pt &b) {
    if (a.id == b.id) return;
    ll dist = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    if (dist < min_dist2) {
        min_dist2 = dist;
        best_pair = {a, b};
    }
}

void solve(int l, int r) {
    if (r-l <= 3) {
        for (int i = l; i < r; i++) 
            for (int j = i+1; j < r; j++)
                upd_ans(a[i], a[j]);
        sort(a.begin()+l, a.begin()+r, cmp_y);
        return;
    }

    int m = (l+r)/2;
    ll midx = a[m].x;

    solve(l, m); 
    solve(m, r);

    merge(a.begin()+l, a.begin()+m, a.begin()+m, a.begin()+r, aux.begin(), cmp_y);
    copy(aux.begin(), aux.begin()+r-l, a.begin()+l);

    int aux_sz = 0;
    for (int i = l; i < r; i++) {
        if ((a[i].x-midx)*(a[i].x-midx) < min_dist2) {
            for (int j = aux_sz-1; j >= 0 && (a[i].y-aux[j].y)*(a[i].y-aux[j].y) < min_dist2; j--)
                upd_ans(a[i], aux[j]);
            aux[aux_sz++] = a[i];
        }
    }
}

ll dx[4] = {1, -1, 1, -1};
ll dy[4] = {1, 1, -1, -1};

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n;

    ll x, y;
    fr(i, n) {
        cin >> x >> y;
        fr(k, 4) 
            a.pb({x*dx[k], y*dy[k], i+1, k+1});
    }

    n *= 4;
    sort(all(a), cmp_x);
    aux.resize(n);
    min_dist2 = LLONG_MAX;
    
    solve(0, n);

    if (best_pair.f.k == 1) best_pair.f.k = 4;
    else if (best_pair.f.k == 2) best_pair.f.k = 3;
    else if (best_pair.f.k == 3) best_pair.f.k = 2;
    else best_pair.f.k = 1;

    cout << best_pair.f.id << " " << best_pair.f.k << " " << best_pair.s.id << " " << best_pair.s.k << '\n';
}
