#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
#define dbgpt(x) cout << #x << " = " << x.f << " " << x.s << endl
#define all(x) x.begin(),x.end()
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

typedef pair<double, double> pt;

int is_left(pt a, pt b, pt c) {
    double det = (b.f-a.f)*(c.s-a.s) - (c.f-a.f)*(b.s-a.s);
    if (det > 0) return 1;  // c is to the left
    if (det < 0) return -1; // c is to the right
    return 0;               // c is collinear
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fastio;

    ll n;
    cin >> n;

    pt p[n];
    fr(i, n) cin >> p[i].f >> p[i].s;

    cout << setprecision(8) << fixed;

    pair<double, int> ans = {-1.0, 0};
    for (int k = 3; k <= 8; k++) {

        double alpha = double(k-2) * 180.0 / double(k);
        double rot = 180.0 - alpha;
        double aout, ain;

        auto f1 = [&] (double dist) {
            double cx = dist, cy = 0.0;
            vector<pt> per;
            per.pb({cx, cy});
            fr(i, k) {
                double nx = cos(rot * acos(-1)/180.0)*(cx) - sin(rot * acos(-1)/180.0)*(cy);
                double ny = sin(rot * acos(-1)/180.0)*(cx) + cos(rot * acos(-1)/180.0)*(cy);
                cx = nx;
                cy = ny;
                per.pb({cx, cy});
            }

            fr(i, k) {
                fr(j, n) {
                    if (is_left(per[i], per[i+1], p[j]) == -1) {
                        //dbg(k);
                        //dbgpt(per[i]);
                        //dbgpt(per[i+1]);
                        //dbgpt(p[j]);
                        //p("-------------------");
                        return 0;
                    }
                }
            }
            return 1;
        };


        // feixo de fora, mais longe
        double eps = 1e-9;
        double l = 0.0, r = 1e9;
        while (r - l > eps) {
            double m = (r+l) / 2.0;
            bool f = f1(m);     
            if (f) r = m;
            else   l = m;
        }
        aout = l * l * sin(rot * acos(-1)/180.0);

        auto f2 = [&] (double dist) {
            double cx = dist, cy = 0.0;
            vector<pt> per;
            per.pb({cx, cy});
            fr(i, k) {
                double nx = cos(rot * acos(-1)/180.0)*(cx) - sin(rot * acos(-1)/180.0)*(cy);
                double ny = sin(rot * acos(-1)/180.0)*(cx) + cos(rot * acos(-1)/180.0)*(cy);
                cx = nx;
                cy = ny;
                per.pb({cx, cy});
            }

            //for (auto x: per) dbgpt(x);
            fr(j, n) {
                int cnt = 0;
                fr(i, k) {
                    if (is_left(per[i], per[i+1], p[j]) >= 0) cnt++;
                }
                if (cnt == k) return 0;
            }
            return 1;
        };

        // feixo de dentro, mais perto
        l = 0.0, r = 1e9;
        while (r - l > eps) {
            double m = (r+l) / 2.0;
            bool f = f2(m);     
            if (f) l = m;
            else   r = m;
        }
        //dbg(l);
        ain = l * l * sin(rot * acos(-1)/180.0);

        //dbg(k);
        //dbg(ain);
        //dbg(aout);
        //p("-------");
        ans = max(ans, {ain/aout, k});
    }

    cout << ans.s << " " << ans.f << endl;
}