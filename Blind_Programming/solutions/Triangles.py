import math

n = int(input())
angles = sorted([(lambda x: math.atan2(x[1], x[0]) + math.pi)(list(map(int, input().split()))) for i in range(n)])
j = 1
res = 0
for i in range(n):
    while j < i + n and angles[j % n] + (j // n) * math.tau < angles[i] + math.pi:
        j+=1
    if j - i > 2:
        res += (j - i - 1) * (j - i - 2)

print(int(n * (n-1) * (n-2) / 6 - res / 2))