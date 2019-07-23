
// Generate all subset sums of the given set s
void sum_of_all_subset ( vl s ) {

    int n = s.size() ;
    ll results[ ( 1<<n ) ];

    ms(results, 0ll);

    // Iterating through all possible combinations
    fr(i, (1<<n))
        fr(j, n)
            // Check if the j-th number is part of the combination
            if ( i & ( 1<<j ))
                results[i] += s[j];

    // The main ideia behind the use of the two for's above is to iterate
    // through all possible sets and combinations. This method can be exploited
    // in a big variaty of problems that make necessary the generation of all
    // possible sets.
}
