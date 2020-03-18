/* 
    CLOSEST PAIR OF POINTS
    O(nlogn)
*/ 

struct pt {
    long long int x, y, id;
};

int n; 
long long int min_dist2;
pair<int, int> best_pair;
vector<pt> a, aux;

bool cmp_x(pt &a, pt &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_y(pt &a, pt &b) {
    return a.y < b.y;
}

void upd_ans(pt &a, pt &b) {
    long long int dist = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    if (dist < min_dist2) {
        min_dist2 = dist;
        best_pair = {a.id, b.id};
    }
}

void solve(int l, int r) {
    if (r-l <= 3) {
        for (int i = l; i < r; i++) 
            for (int j = i+1; j < r; j++) 
                upd_ans(a[i], a[j]);
        sort(a.begin()+l, a.begin()+r, cmp_y);
        return;
    }

    int m = (l+r)/2;
    long long int midx = a[m].x;
    solve(l, m);
    solve(m, r);

    merge(a.begin()+l, a.begin()+m, a.begin()+m, a.begin()+r, aux.begin(), cmp_y);
    copy(aux.begin(), aux.begin()+r-l, a.begin()+l);

    int aux_sz = 0;
    for (int i = l; i < r; i++) {
        if ((a[i].x-midx)*(a[i].x-midx) < min_dist2) {
            // for (int j = aux_sz-1; j >= 0 && (a[i].y-aux[j].y)*(a[i].y-aux[j].y) < min_dist2; j--)
            for (int j = aux_sz-1; j >= max(0, aux_sz-7); j--) // for distinct points only
                upd_ans(a[i], aux[j]);
            aux[aux_sz++] = a[i];
        }
    }
}

int main() {
    aux.resize(n);
    sort(a.begin(), a.end(), cmp_x);
    min_dist2 = LLONG_MAX;
    solve(0, n);
}