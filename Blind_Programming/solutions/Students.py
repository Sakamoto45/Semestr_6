from math import floor
n = int(input())
print(-1 if (n % 2 == 1 or n < 4) else floor((n * 3 - 2) / 4))