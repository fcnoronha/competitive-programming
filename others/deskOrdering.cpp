//training.olinfo.it/#/task/ois_desk/statement

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

int aux[6];

struct minq {

    stack< pair<int, pii> > s1, s2;
    
    int size() {
        return s1.size() + s2.size();
    }

    pii get() {
        if (s1.empty()) return s2.top().s;
        if (s2.empty()) return s1.top().s;
        int idx = 0;
        aux[idx++] = s1.top().s.f;
        aux[idx++] = s1.top().s.s;
        aux[idx++] = s2.top().s.f;
        aux[idx++] = s2.top().s.s;
        sort(aux, aux+idx); reverse(aux, aux+idx);
        return make_pair(aux[0], aux[1]);
    }

    void insert(int val) {
        int idx = 0;
        if (!s1.empty()) {
            aux[idx++] = val;
            aux[idx++] = s1.top().s.f;
            aux[idx++] = s1.top().s.s;
            sort(aux, aux+idx); reverse(aux, aux+idx);
            s1.push({val, {aux[0], aux[1]}});
        }
        else 
            s1.push({val, {val, -INF}});
    }

    void pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int val = s1.top().f;
                s1.pop();
                if (!s2.empty()) {
                    int idx = 0;
                    aux[idx++] = val;
                    aux[idx++] = s2.top().s.f;
                    aux[idx++] = s2.top().s.s;
                    sort(aux, aux+idx); reverse(aux, aux+idx);
                    s2.push({val, {aux[0], aux[1]}});
                }
                else 
                    s2.push({val, {val, -INF}});
            }
        }
        s2.pop();
    }
};

int main() {
    fastio;

    int l, n, ans = INF;
    cin >> n >> l;

    int h[n];
    fr(i, n) cin >> h[i];

    minq s;
    fr(i, l) s.insert(h[i]);

    for (int i = l; i < n; i++) {

        auto aux = s.get(); 
        //dbg(aux.f); dbg(aux.s); p("----");
        if (aux.f - aux.s <= 1) ans = 0;
        ans = min(ans, (aux.f-aux.s)/2);
        s.pop();
        s.insert(h[i]);
    }
    auto aux = s.get(); 
    if (aux.f - aux.s <= 1) ans = 0;
    ans = min(ans, (aux.f-aux.s)/2);

    p(ans);
}
