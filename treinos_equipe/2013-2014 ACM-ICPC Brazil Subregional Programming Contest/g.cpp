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

int m[500][500];

int min_swaps(vector<int> v) {

    int n = v.size();
    pair<int, int> v_pos[n];
    for (int i = 0; i < n; i++) {
        v_pos[i].first = v[i];
        v_pos[i].second = i;
    }
 
    sort(v_pos, v_pos+n);
    vector<bool> vis(n, false);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] || v_pos[i].second == i)
            continue;
 
        int cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;
            j = v_pos[j].second;
            cycle_size++;
        }

        if (cycle_size) ans += (cycle_size - 1);
    }
 
    return ans;
}

signed main() {

    fastio;
	int l, c;
    cin >> l >> c;
    
    int cnt = 1, ii, jj;
    fr(i, l) fr(j, c) {
        cin >> m[i][j];
        if (m[i][j] == 1) ii = i, jj = j;
    }

    vector<int> primeiraLinha;
    vector<int> primeiraColuna;
    int ans = 0;
    for(int i = 0; i<c; i++) primeiraLinha.pb(m[0][i]);
    for(int i = 0; i<l; i++) primeiraColuna.pb(m[i][0]);
    ans = min_swaps(primeiraLinha) + min_swaps(primeiraColuna);

    //// check
    //map<int, int> pos;
    //fr(j, c) pos[m[ii][j]] = j;
    //fr(k, c) {
    //    int u = k, v = pos[k+1]; 
    //    pos[m[ii][k]] = v;
    //    fr(i, l) swap(m[i][u], m[i][v]); 
    //}

    vi linha;
    fr(j, c) linha.pb(m[0][j]%c);
    fr(i, l) {
        vi aux;
        fr(j, c) aux.pb(m[i][j]%c);
        if (aux != linha) {
            p("*");
            return 0;
        }
    }
 

    vi colu;
    fr(i, l) colu.pb((m[i][0]+c-1)/c);
    fr(j, c) {
        vi aux;
        fr(i, l) aux.pb((m[i][j]+c-1)/c);
        if (aux != colu) {
            p("*");
            return 0;
        }
    }

    cout << ans << endl;
}
