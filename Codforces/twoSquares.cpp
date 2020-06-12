//codeforces.com/contest/993/problem/A
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

#define x first
#define y second
typedef pair<int, int> point;

typedef vector<pair<int, int>> polygon;

// testa se o ponto c esta a esquerda da reta a->b
int is_left(point a, point b, point c) {
    int det = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
    if (det > 0) return 1;  // c esta a esquerda
    if (det < 0) return -1; // c esta a direita
    return 0;               // c é colinear
}

// checa se o ponto q esta dentro do poligono p
bool is_inside(polygon p, point q) {
    int n = p.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[is_left(p[i], p[(i+1)%n], q)]++;
    return (mp[1] == 0 || mp[-1] == 0); 
}

bool is_inside_le(polygon p, point q) {
    int n = p.size();
    for (int i = 0; i < n; i++)
        if (is_left(p[i], p[(i+1)%n], q) > 0)
            return false;
    return true;
}

int main() {
    fastio;

    polygon square_1, square_2;
    fr(k, 4) {
        int x, y;
        cin >> x >> y;
        square_1.push_back({4*x, 4*y});
    }
    fr(k, 4) {
        int x, y;
        cin >> x >> y;
        square_2.push_back({4*x, 4*y});
    }

    point c1 = {0, 0};
    for (auto pt: square_1) {
        if (is_inside(square_2, pt)) {
            cout << "YES" << endl;
            return 0;
        }
        c1.x += pt.x;
        c1.y += pt.y;
    }
    c1.x /= 4, c1.y /= 4;
    if (is_inside(square_2, c1)) {
        cout << "YES" << endl;
        return 0;
    }

    point c2 = {0, 0};
    for (auto pt: square_2) {
        if (is_inside(square_1, pt)) {
            cout << "YES" << endl;
            return 0;
        }
        c2.x += pt.x;
        c2.y += pt.y;
    }
    c2.x /= 4, c2.y /= 4;
    if (is_inside(square_1, c2)) {
        cout << "YES" << endl;
        return 0;
    }

    p("NO");
}
