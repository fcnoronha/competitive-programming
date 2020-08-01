// KMP O(n+m)


// lps[i] = biggest prefix in p[0...i] wich is also suffix in p[0...i].
vector<int> get_lps(string p) {
    int n = p.size(), i = 1, len = 0; // size of last prefix sufix
    vector<int> lps(n, 0);
    while (i < n) {
        if (p[i] == p[len]) lps[i++] = ++len;
        else if (len != 0)  len = lps[len-1];
        else                lps[i++] = 0;
    }
    return lps;
}

void kmp(string pat, string txt){
    vector<int> lps = get_lps(pat);
    // i for pat and j for txt
    int i = 0, j = 0, m = pat.size(), n = txt.size();
    while (i < n) {
        if (pat[j] == txt[i]) j++, i++;
        if (j == m) {
            printf("found match at %d\n", i-j);
            j = lps[j-1];
        }
        else if (i < n && pat[j] != txt[i]) {
            if (j) j = lps[j-1];
            else   i = i+1;
        }
    }
}