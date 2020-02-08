// EULER PATH

/*
	The ideia of a path in the graph that visits all vertices only once.
	In order to exist such path the graph needs to attend ONE of the 
	two following rules:
		- Every vertex in the graph has to have a odd (par) deegre, so
		every vertex can be the end or the start of the path;
		- The preview rule, but with two vertices with a even (impar)
		deegre, these will be the start and the end of the path.
*/

vector<int> path;
vector<int> adj[MAXN];
map< pair<int, int>, bool > del;

void findPath(int v){
	// 'v' is the initial vertex

	for (auto u : adj[v]){
		if (del[{v, u}]) continue;

		// Now we 'delete' the vertex and make a call for recursion
		del[{v, u}] = true;
		del[{u, v}] = true;

		findPath(u);
	}

	path.pb(v);
}