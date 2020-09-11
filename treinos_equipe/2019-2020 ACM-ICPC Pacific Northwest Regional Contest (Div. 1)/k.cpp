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
typedef unsigned char uc;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

struct node{
    int mem, i, val;
    node(){
        mem = i = -1;
        val = 0;
    }
    node(int aa, int bb, int cc){
        mem=aa, i=bb, val = cc;
    }
    const node operator+(node& a){
        if(a.mem != -1){
            (*this) = a;
        }
        return (*this);
    }
};

template <class T>
class SegTree{
	public:
	vector<T> seg, lazy, v;
	vi hi, lo;
	function<T(T, T)> upd;
	function<void(vi&, vi&, vector<T>&, vector<T>&, int)> unlzy;
	T LIXO;
	SegTree(int n, T lx, vector<T>& vec, const function<T(T, T)>& updt, 
		const function<void(vi&, vi&, vector<T>&, vector<T>&, int)>& U)
	{
		v = vec, upd = updt, unlzy = U;
		hi.resize(4*n + 1), lo.resize(4*n + 1),	seg.resize(4*n + 1), lazy.resize(4*n + 1);
		LIXO = lx;
		build(1, 0, n-1);
	}

	T build(int nd, int start, int end){
		lo[nd] = start; hi[nd] = end;
		if(start == end){
			return seg[nd] = v[start];
		}
		int mid = (end+start)/2;
		return seg[nd] = upd(build(2*nd, start, mid), build(2*nd + 1, mid + 1, end)); 
	}

	void unlazy(int nd){
		unlzy(hi, lo, seg, lazy, nd);
	}

	T query(int nd, int start, int end){
		unlazy(nd);
		if(hi[nd] < start || lo[nd] > end) return LIXO;
		if(lo[nd] >= start && hi[nd] <= end) return seg[nd];
		return upd(query(2*nd, start, end), query(2*nd + 1, start, end));
	}

	void change(int nd, int start, int end, T x){
		unlazy(nd);
		if(hi[nd] < start || lo[nd] > end) return;
		if(lo[nd] >= start && hi[nd] <= end){
			lazy[nd] = lazy[nd] + x;
			unlazy(nd);
			return;
		}
		change(2*nd, start, end, x);
		change(2*nd+1, start, end, x);
		seg[nd] = upd(seg[2*nd], seg[2*nd+1]);
	}
};

node update(node a, node b){
    if(a.mem != -1) return a;
    return b;
}

void unlazy(vi& hi, vi& lo, vector<node>& seg, vector<node>& lazy, int cur){
    seg[cur] + lazy[cur];
    if(hi[cur] != lo[cur]){
        lazy[2*cur] + lazy[cur];
        lazy[2*cur+1] + lazy[cur];
    }
    lazy[cur] = node(-1, -1, 0);
}

uc up(uc a, uc b){
    return max(a, b);
}

void unlz(vi& hi, vi& lo, vector<uc>& seg, vector<uc>& lazy, int cur){
    seg[cur] += lazy[cur];
    if(hi[cur] != lo[cur]){
        lazy[2*cur] += lazy[cur];
        lazy[2*cur + 1] += lazy[cur];
    }
    lazy[cur] = 0;
}

int main(){
    rvr(n); rvr(m);
    rvr(q);
    vector<vector<uc>> memo(m);
    vector<SegTree<uc>> mem;
    fr(i, m){
        rvr(s);
        fr(j, s){
            uc a; scanf("%hhu", &a);
            memo[i].pb(a);
        }
        mem.pb(SegTree<uc>(s, 0, memo[i], up, unlz));
    }
    node lx = node(-1, -1, 0);
    vector<node> vec(n, lx);
    SegTree<node> seg(n, lx, vec, update, unlazy);
    vector<pair<int, pii>> vecchg;
    vector<pii> otp;
    vector<pair<int, pair<int, pii>>> memchg;
    frr(i, q){
        rvr(s);
        if(s == 1){
            int ii, pp; scanf("%d%d", &ii, &pp);
            vecchg.pb(mp(i, mp(ii - 1, pp - 1)));
        }
        else if(s == 2){
            rvr(ii);
            otp.pb(mp(i, ii-1));
        }
        else{
            int ii, ll, rr; scanf("%d%d%d", &ii, &ll, &rr);
            memchg.pb(mp(i, mp(ii - 1, mp(ll - 1, rr - 1))));
        }
    }
    int ps = otp.size(), ms = memchg.size(), vs = vecchg.size();
    int i = 0, j = 0, k = 0;
    vector<pii> nxt;
    vector<node> vaca;
    vector<uc> final(ps);
    while(i < ps){
        while(j < vs && otp[i].ff > vecchg[j].ff){
            seg.change(1, vecchg[j].ss.ss, vecchg[j].ss.ss - 1 + memo[vecchg[j].ss.ff].size(), node(vecchg[j].ss.ff, vecchg[j].ss.ss, vecchg[j].ff));
            j++;
        }
        node plc = seg.query(1, otp[i].ss, otp[i].ss);
        vaca.pb(plc);
        if(plc.mem == -1){
            nxt.pb(mp(0, i));
        }
        else nxt.pb(mp(plc.val, i));
        i++;
    }
    sort(all(nxt));
    i=0;
    while(i < ps){
        while(k < ms && nxt[i].ff > memchg[k].ff){
            mem[memchg[k].ss.ff].change(1, memchg[k].ss.ss.ff, memchg[k].ss.ss.ss, 1);
            k++;
        }
        if(nxt[i].ff == 0){
            final[nxt[i].ss] = 0;
        }
        else{
            final[nxt[i].ss] = mem[vaca[nxt[i].ss].mem].query(1, otp[nxt[i].ss].ss - vaca[nxt[i].ss].i, otp[nxt[i].ss].ss - vaca[nxt[i].ss].i);
        }
        i++;
    }
    fr(jj, ps){
        printf("%hhu\n", final[jj]);
    }
}
