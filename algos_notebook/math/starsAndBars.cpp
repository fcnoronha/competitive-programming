
/*
    - STARS AND BARS
    The number of ways fo put n identical objects into k labeled boxes is
        (n+k-1) choose (n)

    - Number of non-negative integer sums
    You want to count the number of solution of the equation
        x1 + x2 + ... + xk = n
    just use the above formula

    - Number of lower-bound integer sums
    This can easily be extended to integer sums with different lower bounds. 
    I.e. we want to count the number of solutions for the equation
        x1 + x2 + ... + xk = n, with xi ≥ ai.

    After substituting x'i := xi−ai we receive the modified equation
        (x'1+ai) + (x'2+ai) + ... + (x'k+ak) = n
        <=>  x'1 + x'2 + ... + x'k = n − a1 − a2 − ... − ak
*/