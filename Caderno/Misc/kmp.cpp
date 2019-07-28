//Reconhecendo padroes em texto e algoritimo de KMP

/*
Definindo um padrao p e um texto t:
p = {p0,p1,..,pm}
t = {t0,t2,...,tn}
Ideia de dar um "CTLR+F" em t para achar p.

Algoritimo naive = O(n*m), tetando encaixar p em todas as posiçoes de t.

--------

Usando KMP reduzimos a complexidade para O(n+m)

Para isso, definimos um vetor lps[i] = maior prefixo em p[0...i] que tambem e sufixo em p[0...i].
Por exemplo:        p = A A A A
			      lps = 0 1 2 3

			      	p = A B A C A B A
			      lps = 0 0 2 0 1 2 3

*/

void LPS(char[] pat, int M, int[] lps){

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


void KMP(char[] pat, char[] txt){
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M]; // Vetor para armazenar lps

    LPS(pat, M, lps);

    int i = 0; // index para txt[]
    int j = 0; // index para pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Achei um padrao aq %d ", i - j);
            j = lps[j - 1];
        }

        // mismatch
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

//www.youtube.com/watch?v=btr95inWBaQ -> video aula
//codeforces.com/group/eqgxxTNwgd/contest/101245 -> Lista ex
