import fileinput
import math

def quick_power(a, power, mod):
    res = 1
    while power:
        if power & 1:
            res *= a
            res %= mod
        a *= a
        a %= mod
        power >>= 1
    return res

x = [int(line) for line in fileinput.input(files ='Py/lcg_seq_2022.txt')]
y = [x[i+1] - x[i] for i in range(len(x) - 1)]
z = [y[i] * y[i+2] - y[i+1]**2 for i in range(len(y) - 2)]
M = z[0]
for num in z:
    M = math.gcd(M, num)
A = (y[1] * quick_power(y[0], M - 2, M)) % M
C = (x[1] - x[0] * A) % M

print('A = ', A)
print('C = ', C)
print('M = ', M)