from math import factorial
 
n = int(input())
n = n + 1

x = 1
for i in range(2*n, n, -1):
    x = x*i

x = x//factorial(n)

x = x//(n+1)
print(x)