import fileinput
import math

def is_prime(num):
    for i in range(2, int(math.sqrt(num))):
        if num % i == 0:
            return False
    return True

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

try:
    x = [int(line) for line in fileinput.input(files ='Py/lcg_seq_2022.txt')]
    y = [x[i+1] - x[i] for i in range(len(x) - 1)]
    z = [y[i] * y[i+2] - y[i+1]**2 for i in range(len(y) - 2)]

    M = z[0]
    for num in z:
        M = math.gcd(M, num)
    if (not is_prime(M)):
        raise ValueError('M is not prime')

    A = [(y[i + 1] * quick_power(y[i], M - 2, M)) % M for i in range(len(y) - 1)]
    if max(A) != min(A):
        raise ValueError('A defined ambiguously')
    A = A[0]

    C = [(x[i + 1] - x[i] * A) % M for i in range(len(x) - 1)]
    if max(C) != min(C):
        raise ValueError('C defined ambiguously')
    C = C[0]

    print('A = ', A)
    print('C = ', C)
    print('M = ', M)

except ValueError as e:
    print(e)