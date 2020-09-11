
n, s = [int(x) for x in input().split(' ')]

v = []
for i in range(n):
    t, b = [x for x in input().split(' ')]
    b = int(b)
    v.append((b, t))

ans = []
for x in reversed(sorted(v)):
    if (x[0] <= s):
        s -= x[0]
        ans.append(x[1])

if s > 0:
    print(0)
else:
    print(len(ans))
    for x in ans:
        print(x)