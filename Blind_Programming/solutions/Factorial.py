n = int(input())
a = int(input())

def factorise(n):
    res = {}
    d = 2
    while d*d < n:
        if n % d == 0:
            res[d] = 0
            while n % d == 0:
                res[d] += 1
                n //= d 
        d += 1

    if n != 1:
        res[n] = 1
    return res

def count(n, prime):
    res = 0
    while n:
        n //= prime
        res += n
    return res

print(min([count(n, prime) // power for prime, power in factorise(a).items()]))