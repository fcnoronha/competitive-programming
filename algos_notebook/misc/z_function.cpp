// Z-function O(n)

// ith element is equal to the greatest number of characters starting from the
// position i that coincide with the first characters of s.
// In other words, z[i] is the length of the longest common prefix between s 
// and the suffix of s starting at i.

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i, r = i+z[i]-1;
    }
    return z;
}

/* Search the substring: find occurrences of pattern p inside text t
Create a new string s=p+'&'+t. Compute the Z-function for s. Then, for 
i in [0,|t|−1], we define ki = z[i+|p|+1]. If ki is equal to |p| we know
there is one occurrence of p in the i-th position of t.
*/

/* String compression:
Given a string s of length n, find a string t of shortest length such that s 
can be represented as a concatenation of one or more copies of t.
compute the Z-function of s, loop through all i such that i divides n. 
Stop at the first i such that i+z[i]=n, the string s can be compressed 
to the length i.
*/