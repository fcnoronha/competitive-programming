#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
#define pv(x, n)    fr(iii, n) printf("%d%c", x[iii], " \n"[iii==n-1])
#define pvv(x, n)    frr(iii, n) printf("%d%c", x[iii], " \n"[iii==n])
#define vp(v)        pv(v, v.size()) 


#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define otp(x) cout << x << endl;
#define rvr(x) int x; scanf("%d", &x)
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int N = 100001;

struct vote{
    int a, b, c;
};

vector<vote> freq[26];
vector<bool> can(26, true);

int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        fr(i, 26){
            can[i] = false;
            freq[i].clear();
        }
        fr(i, n){
            string s; cin >> s;
            vote v;
            v.a = s[0] - 'A';
            can[v.a] = true;
            if(s.size() > 1){
                v.b = s[1] - 'A';
                can[v.b] = true;
                if(s.size() > 2){
                    v.c = s[2] - 'A';
                    can[v.c] = true;
                }
                else v.c = -1;
            } 
            else v.b = v.c = -1;
            freq[v.a].pb(v); 
        }
        bool run = true;
        while(run){
            int mx = -1, mn = N, idx = -1;
            vi out;
            fr(i, 26){
                int plc = freq[i].size();
                if(plc > mx){
                    idx = i;
                    mx = plc;
                }
                if(can[i] && mn > plc){
                    out.clear();
                    mn = plc;
                }
                if(plc == mn && can[i]) out.pb(i);
            }
            //printf("\n");
            for(auto o: out) can[o] = false;
            if(mx > n/2){
                printf("%c\n", 'A'+idx);
                goto END;
            }
            if(mx == 0){
                printf("no winner\n");
                goto END;
            }
            for(auto cur:out){
                for(auto vv: freq[cur]){
                    if(can[vv.a]){
                        freq[vv.a].pb(vv);
                        continue;
                    }
                    if(vv.b != -1 && can[vv.b]){
                        freq[vv.b].pb(vv);
                        continue;
                    }
                    if(vv.c != -1 && can[vv.c]){
                        freq[vv.c].pb(vv);
                        continue;
                    }
                    n--;
                }
                freq[cur].clear();
                printf("%c", cur+'A');
            }
            printf(" -> ");

        }
        END:;
    }
}
