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

class Wichmann_Hill:
    # s = list((0, 0, 0))
    s = list()

    def __init__(self, seed):
        assert len(seed) == 3
        self.s = list(seed)

    def get_seed(self):
        return self.s

    def WH_next(self):
        self.s[0] = self.s[0] * 171 % 30269
        self.s[1] = self.s[1] * 172 % 30307
        self.s[2] = self.s[2] * 170 % 30323

    def jump_ahead(self, n):
        self.s[0] = self.s[0] * quick_power(171, n, 30269) % 30269
        self.s[1] = self.s[1] * quick_power(172, n, 30307) % 30307
        self.s[2] = self.s[2] * quick_power(170, n, 30323) % 30323

    def value(self):
        return (self.s[0]/30269 + self.s[1]/30307 + self.s[2]/30323) % 1

    def rand(self):
        self.WH_next()
        return self.value()
    
wh1 = Wichmann_Hill((1, 1, 1))

for i in range(1000):
    print(wh1.rand())

wh2 = Wichmann_Hill((1, 1, 1))

wh2.jump_ahead(1000)
print()
print(wh2.value())



