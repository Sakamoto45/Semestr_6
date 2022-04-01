def hash(a):
    res = 2139062143
    for num in a:
        res *= 73
        res += num
    res %= 2147483647
    return res

def permutation(fun, a, pos = 0):
    if pos == len(a):
        fun(a)
    else:
        for i in range(pos, len(a)):
            a[i], a[pos] = a[pos], a[i]
            permutation(fun, a, pos + 1)
            a[i], a[pos] = a[pos], a[i]


for n in range(1, 12):
    min_a = list()
    min_hash = 2147483647


    def find_min(a):
        global min_a
        global min_hash
        a_hash = hash(a)
        if a_hash < min_hash:
            min_hash = a_hash
            min_a = list(a)

    # permutation(lambda x: print(x, hash(x)), list(range(n)))
    permutation(find_min, list(range(1, n+1)))
    print("{}: {},".format(n, min_a))