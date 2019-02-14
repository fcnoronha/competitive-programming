// SQUAREROOT DECOMPOSITION

/* 
	The ideia is to divide an array of size N into parts of size sqrt(N),
	with this, given a query and a range [l, r] you can just get the 
	precalculated answers inside [l, r] and just calculate the answer for
	the limits of [l, r] with sqrt(N) complexity.

	O(sqrt(N)) for each query. 

	The update query complexity will depend on the problem.
*/

// Exemple of using sqrtdecom to calculate range-sum queries

#define MAXN 10000 // TO BE DEFINED
#define MAXSQRT 100 // TO BE DEFINED 

int a[MAXN]; // Original array
int b[MAXSQRT]; // Blocks
int bsz; // Block size

void update(int i, int v){
	// Set i-th value to v
	int bn = i/bsz; // Block number
	b[bn] += v - a[i];
	a[i] = v;
}

int query(int l, int r){
	// Get the sum of all elements in range [l, r]

	int sum = 0;
	// Fist part that doesn't belong to hole block
	while (l < r && l%bsz != 0 && l != 0)
		sum += a[l++];

	// Getting hole blocks sum
	while (l+bsz <= r){
		sum += b[l/bsz];
		l += bsz;
	}

	// Getting last part that doesn't belong to hole block
	while (l <= r)
		sum += a[l++];

	return sum;
}

void prepro(int n){
	// Preprocess all, n is the size

	int bidx = -1; // block pointer
	bsz = sqrt(n);

	// Building decomposed array
	for (int i = 0; i < n; i++){
		
		// Incrading block index accoding to sqrt
		bidx += (i%bsz == 0);

		b[bidx] += a[i];
	}
}

// DONT FORGET TO PREPROCESS


// MO'S ALGORITH

/*
	The ideia of Mo's algo is to sort queries to improve time complexity,
	we will sort them using SQRTdecom blocks as sorting parameters.
	After sorting, the queries will be arranged in the following way:
		All the queries that start (has the L value) on the fisrt block
		will come first;
		All the queries that start (has the L value) on the second block
		will come after;
		So on...

	Now, we can calculate each query using the result of the previews one
	to help generate the actual one.
*/

#define MAXQ 1000 // Maximum number of queries

int bsz; // To be defined in main
pair<int, int> q[MAXQ]; // {l, r};

bool comp(pair<int, int> a, pair<int, int> b){
	// Function to sort my queries

	if (a.first/bsz != b.fisrt/bsz)
		return a.first/bsz < b.fisrt/bsz;

	return a.second < b.second;
}

void mos(int n, int m){
	// n is the number of elements in array a[]
	// m is the number of queries

	bsz = sqrt(n);

	sort(q, q+m, comp);

	// Initializing current l, r and sum
	int cr = 0, cl = 0, csum = 0;

	for (int i = 0; i < m; i++){

		int l = q[i].f;
		int r = q[i].s;

		// Dealing with extra elements from pre query
		while (cl < l)
			csum -= a[cl++];

		// Adding for actual range
		while (cl > l)
			csum += a[--cl];

		while (cr <= r)
			csum += a[cr++];

		while (cr > r+1)
			csum -= a[--cr];

		cout << csum << endl;
	}
}