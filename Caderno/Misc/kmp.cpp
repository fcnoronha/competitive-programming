/*
KMP - O(n+m)

Vetor lps[i] = maior prefixo em p[0...i] que tambem e sufixo em p[0...i].
Por exemplo:        p = A A A A
			      lps = 0 1 2 3

			      	p = A B A C A B A
			      lps = 0 0 2 0 1 2 3
*/

void LPS(string pat, int M, int[] lps){

    int len = 0; // Tamanho do ultimo prefixo sufixo
    lps[0] = 0; // base

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string pat, string txt){
    int M = (int)pat.size();
    int N = (int)txt.size();

    int lps[M]; 
    LPS(pat, M, lps);

    int i = 0; // for txt
    int j = 0; // for pat
    while (i < N) {
        if (pat[j] == txt[i]) 
            j++, i++;
        
        if (j == M) {
            printf("Achei um padrao aq %d ", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}