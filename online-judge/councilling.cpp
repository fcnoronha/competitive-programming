//onlinejudge.org/external/105/10511.pdf

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

struct FlowEdge {
    int u, v;
    ll cap;
    string name = "";
    ll flow = 0;
};

vector<FlowEdge> edges;
vector<vi> adj;
vi level, ptr;
queue<int> q;
int cnt; 
 
void init(int n) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
}

void uninit() {
    edges.clear();
    adj.clear();
    level.clear();
    ptr.clear();
    cnt = 0; 
}
 
void add_edge(int u, int v, ll cap, string name) {
    edges.pb({u, v, cap, name});
    edges.pb({v, u, 0ll, name});
    adj[u].pb(cnt++);
    adj[v].pb(cnt++);
}
 
bool bfs(int t) {
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int id : adj[u]) {
            if (edges[id].cap - edges[id].flow < 1)
                continue;
            if (level[edges[id].v] != -1)
                continue;
            level[edges[id].v] = level[u] + 1;
            q.push(edges[id].v);
        }
    }
    return level[t] != -1;
}
 
ll dfs(int u, ll pushed, int t) {
    if (pushed == 0)
        return 0ll;
    if (u == t)
        return pushed;
    for (int& cid = ptr[u]; cid < adj[u].size(); cid++) {
        int id = adj[u][cid];
        int v = edges[id].v;
        if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
            continue;
        ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow), t);
        if (tr == 0)
            continue;
        edges[id].flow += tr;
        edges[id^1].flow -= tr;
        return tr;
    }
    return 0;
}
 
ll dinic(int s, int t) {
    ll f = 0;
    while (true) {
        fill(all(level), -1);
        level[s] = 0;
        q.push(s);
        if (!bfs(t)) break;
        fill(all(ptr), 0);
        while (ll pushed = dfs(s, LINF, t)) 
            f += pushed;
    }
    return f;
}

int main(){
    fastio;

    int teste;
    cin >> teste;
    string str;
	
	int id;
    getline(cin, str);
    getline(cin, str);
    while (teste--) {

    	id = 2;
    	init(100000);
        map<int, pii> name_v;
        
        // club_ | name_ | party_
    	map<string, int> c_mp, n_mp, p_mp;
    	set<int> c_l, p_l, n_l;
        int p_id, n_id, c_id; 
    	
    	while (getline(cin, str) && str.size()) {
    		
    		istringstream ss(str);
	        string name, party, club;

	        ss >> name;
	        ss >> party;

	        if (p_mp[party] == 0) p_mp[party] = id++;
            p_id = p_mp[party];
            p_l.insert(p_id);
	        
            n_mp[name] = id++;
            n_id = n_mp[name];
            name_v[n_id] = {n_id, id++};
            n_l.insert(n_id);

            add_edge(n_id, name_v[n_id].s, 1, "");
            add_edge(name_v[n_id].s, p_id, 1, "");

	        while(ss >> club) {

	            if (c_mp[club] == 0) c_mp[club] = id++;
                c_id = c_mp[club];
                c_l.insert(c_id);

                add_edge(c_id, n_id, 1, name+" "+club);	            
	        } 
    	}

        int s = id++, t = id++;
        for (auto x: c_l) add_edge(s, x, 1, "");

        int cap = (c_l.size()-1)/2;
    	for (auto x: p_l) add_edge(x, t, cap, "");

    	if (dinic(s, t) != c_l.size()) 
    		p("Impossible.");
    	else 
    		for (auto e: edges) 
    			if (e.flow > 0 && e.name.size())
    				cout << e.name << endl;

    	uninit();
    	if (teste) cout << endl;
    }
}
