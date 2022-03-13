import fileinput
import math

x = list()
for line in fileinput.input(files ='Py/lcg_seq_2022.txt'):
    x.append(int(line))

y = list()
for i in range(len(x) - 1):
    y.append(x[i+1] - x[i])

z = list()
for i in range(len(y) - 2):
    z.append(y[i] * y[i+2] - y[i+1]**2)

# print(x)
# print(y)
# print(z)

try:
    M = z[0]
    for num in z:
        M = math.gcd(M, num)

    # print(M)

    def is_prime(num):
        for i in range(2, int(math.sqrt(num))):
            if num % i == 0:
                return False
        return True

    if (not is_prime(M)):
        raise ValueError('M is not prime')

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

    # mb switch to factorisation of M
    # import sympy
    # primerange(2, math.sqrt(M)+1)
    A = list()
    for i in range(len(y) - 1):
        A.append((y[i + 1] * quick_power(y[i], M - 2, M)) % M)

    # print(A)
    A = A[0]

    C = list()
    for i in range(len(x) - 1):
        C.append((x[i + 1] - x[i] * A) % M)

    # print(C)
    C = C[0]

    print('A = ', A)
    print('C = ', C)
    print('M = ', M)


except ValueError as e:
        print(e)

