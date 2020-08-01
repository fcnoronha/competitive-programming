// Manacher's Algorithm 
// Count all sub-palindromes of a string in O(N)

// d1[i]: number of palindromes with odd length centered in s[i]
// d2[i]: number of palindromes with even length centered in s[i-1]s[i]
// s:  B A A B A
// d1: 1 1 1 2 1
// d2: 0 0 2 0 0

ll manacher(string &s) {
    int n = s.size(), d1[n], d2[n];
    ll sm = 0ll;

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
        while (0 <= i-k && i+k < n && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        sm += d1[i];
        if (i+k > r) {
            l = i-k;
            r = i+k;
        }
    }

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while (0 <= i-k-1 && i+k < n && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        sm += d2[i];
        if (i+k > r) {
            l = i-k-1;
            r = i+k ;
        }
    }

    return sm;
}

