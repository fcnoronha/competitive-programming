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

    map<pii, double> pd;
    pii v[151];
    int n;

    double solve(int i, int somaAt){
        if(i >= n && somaAt>=76) return 1;
        if(i>=n) return 0; 
        if(pd.count({i,somaAt}) != 0) return pd[{i,somaAt}];

        double cara1 = solve(i+1, somaAt);
        double cara2 = ((double)v[i].s/100.0) * solve(i+1, somaAt + v[i].f);
        return pd[{i,somaAt}] = max(cara1, cara2);
    }


    int main(){
        fastio;
        int t;
        cin >> t;
        while(t--){
            pd.clear();
            cin >> n;
            fr(i,n)
                cin >> v[i].f >> v[i].s;
            cout << fixed;
            cout << setprecision(6);
            cout << solve(0,0)*100.0 << endl;

        }
    }
