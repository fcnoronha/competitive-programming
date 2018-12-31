// BIPARTILE CHECK

/*

	Find if a graph is bipartile. Hence, it can be divided into two
	disjoint sets in wich every edge connects only to vertices of 
	the other set.

*/

int n; // Number of vertices
vector<int> adj[MAXN];
int rep[MAXN];

void set(int x){
	// Try to define a set for vertex 'x'

	rep[x] = 0;

	queue<int> q; // For the BFS
	q.push(x); 

	while (!q.empty()){

		int act = q.front();
		q.pop();

		for (auto u : adj[act]){

			if (rep[u] == -1){
				// Set still not defined
				rep[u] = !rep[act]; // Different set from actual
				q.push(u);
			}
		}
	}
}

int main(){

	for (int i = 0; i < n; i++) rep[i] = -1;

	// We call set() from avery vertex in the graph
	for (int i = 0; i < n; i++)
		if (rep[i] == -1) 
				set(i);

	// Now we check if there are two connected vertices in the same set
	for (int i = 0; i < n; i++)
		for (auto u : adj[i])
			if (rep[u] == rep[v])
				return false; // Meeeee

	return true;
}