// codeforces.com/problemset/problem/455/D

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

struct block{
    int cnt[100100];
    deque<int> arr;
} v[400];

int main(){
    fastio;
    
    int n;
    cin >> n;

    int bsz = static_cast<int>(sqrt(n));
    int x;

    fr(i, n) {
        
        cin >> x;
        int bl = i/bsz;
        
        v[bl].arr.pb(x);
        v[bl].cnt[x]++;
    }
    
    int q;
    cin >> q;
    int lst_ans = 0;

    fr(i, q){

        int type;
        cin >> type;
        
        if (type == 1) {

            int l, r;
            cin >> l >> r;  

            l = (l+lst_ans-1)%n + 1;
            l--;
            r = (r+lst_ans-1)%n + 1;
            r--;
            
            if(l > r) swap(l, r);
            
            int lst = r/bsz;
            int fst = l/bsz;

            l %= bsz;
            r %= bsz;

            if (fst == lst) {

                auto &b = v[fst];

                int aux = b.arr[r];
                b.arr.erase(b.arr.begin() + r);
                b.arr.insert(b.arr.begin() + l, aux);

                continue;
            }

            int sai = v[lst].arr[r];
            v[lst].cnt[sai]--;
            v[lst].arr.erase(v[lst].arr.begin()+r);
            
            int aux = v[fst].arr.back();
            v[fst].arr.pop_back();
            v[fst].cnt[aux]--;

            v[fst].arr.insert(v[fst].arr.begin()+l, sai);
            v[fst].cnt[sai]++;

            for (int bl = fst+1; bl < lst; bl++) {
                v[bl].arr.push_front(aux);
                v[bl].cnt[aux]++;
                
                aux = v[bl].arr.back();
                v[bl].cnt[aux]--;
                v[bl].arr.pop_back();
            }

            v[lst].arr.push_front(aux);
            v[lst].cnt[aux]++;
        
        } else {

            int l, r, k;
            cin >> l >> r >> k;

            l = (l+lst_ans-1)%n + 1;
            r = (r+lst_ans-1)%n + 1;
            k = (k+lst_ans-1)%n + 1;
            if(l > r) swap(l,r);
            l--;
            r--;

            int ans = 0;

            int fst = l/bsz;
            int lst = r/bsz;

            l %= bsz;
            r %= bsz;

            if (fst == lst) {
    
                for (; l <= r; l++)
                    ans += (v[lst].arr[l] == k);

                lst_ans = ans;
                cout << ans << endl;
                continue;
            }

            for(int j = fst+1; j < lst; j++) 
                ans += v[j].cnt[k];
            
            for(int j = l; j < bsz; j++)
                ans += (v[fst].arr[j] == k);
            
            for(int j = 0; j <= r; j++)
                ans += (v[lst].arr[j] == k);
            
            lst_ans = ans;
            cout << ans << endl;
        } 
    }
}
