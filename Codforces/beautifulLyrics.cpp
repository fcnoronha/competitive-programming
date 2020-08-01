//codeforces.com/contest/1182/problem/C

#include "bits/stdc++.h"
using namespace std;

#define f first
#define s second
#define pb push_back
#define fr(i, n) for(int i = 0; i < n; i++)
#define frr(i, n) for(int i = 1; i <= n; i++)
#define dbg(x) cout << #x << " = " << x << endl
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

pair<int, char> cnt_v(string &s) {
    int cnt = 0;
    char lst = '1';
    for (auto c: s) 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
            cnt++, lst = c;
    return {cnt, lst};
}

int main() {
    fastio;

    int n;
    cin >> n;

    string s[n];
    map<pair<int,char>, set<int>> mp;
    fr(i, n) {
        cin >> s[i];
        auto oi = cnt_v(s[i]);
        if (oi.f == 0) continue;
        mp[oi].insert(i);
    }

    vector< pair<pii, pii> > ans;
    int idx = 0;

    for (auto &x: mp) {
        while (x.s.size() >= 2) {
            int i = *x.s.begin();
            x.s.erase(x.s.begin());
            int j = *x.s.begin();
            x.s.erase(x.s.begin());
            ans.pb({{-1, i}, {-1, j}});
        }
    }

    map<int, set<int>> mpp;
    for (auto &x: mp) 
        for (auto y: x.s) 
            mpp[x.f.f].insert(y);
    
    for (auto &x: mpp) {
        if (idx == ans.size()) break;
        while (x.s.size() >= 2) {
            if (idx == ans.size()) break;
            int i = *x.s.begin();
            x.s.erase(x.s.begin());
            int j = *x.s.begin();
            x.s.erase(x.s.begin());
            ans[idx].f.f = i;
            ans[idx].s.f = j;
            idx++;
        }
    }

    int ridx = ans.size()-1;
    while (idx < ridx) {

        ans[idx].f.f = ans[ridx].f.s;
        ans[idx].s.f = ans[ridx].s.s;

        ridx--;
        idx++;
    }


    p(idx);
    fr(i, idx) {
        cout << s[ans[i].f.f] << " " << s[ans[i].f.s] << '\n';
        cout << s[ans[i].s.f] << " " << s[ans[i].s.s] << '\n';
    }
}
