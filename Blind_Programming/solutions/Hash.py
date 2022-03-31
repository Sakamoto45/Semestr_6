def hash(a):
    res = 2139062143
    for num in a:
        res *= 73
        res += num
    res %= 2147483647
    return res


n = int(input())

