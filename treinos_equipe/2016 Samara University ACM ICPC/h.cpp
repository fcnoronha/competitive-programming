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

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int main(){
    fastio

    string s;
    cin >> s;

    bool vis[s.size()];
    ms(vis, 0);

    stack<int> abrindo, dont;
    fr(i, s.size()) {

        if (s[i] == '(') {
            abrindo.push(i);
            continue;
        }

        if (s[i] == '?') {
            dont.push(i);
            continue;
        }

        if (abrindo.size()) {

            int idx = abrindo.top();
            abrindo.pop();

            vis[idx] = vis[i] = 1;
            continue;
        }

        if (dont.size()) {

            int idx = dont.top();
            dont.pop();

            vis[idx] = vis[i] = 1;
            s[idx] = '(';
            continue;
        }

        p("Impossible");
        return 0;
    }

    stack<int> aux;
    while (!dont.empty()) {
        aux.push(dont.top());
        dont.pop();
    }
    dont = aux;

    int cnt = 1;
    int quero = 0;
    fr(i, s.size()) {

        if (vis[i]) continue;

        if (s[i] == '(') {
            quero++;
            continue;
        }

        if (dont.size()) {


            int idx = dont.top();
            dont.pop();

            if (quero) {
                s[idx] = ')';
                vis[idx] = 1;
                quero--;
                continue;
            }

            if (cnt) s[idx] = '(', cnt=0;
            else s[idx] = ')', cnt=1;
            vis[idx] = 1;
        }
    }

    if (dont.size()%2) {
        p("Impossible");
        return 0;
    }

    stack<char> ola;
    fr(i, s.size()) {
        if (s[i] == '(') ola.push('(');
        else {
            if (ola.size() == 0) {
                p("Impossible");
                return 0;
            }
            ola.pop();
        }
    }
    if (ola.size()) {
        p("Impossible");
        return 0;
    }

    p(s);
}
