from random import randrange

n = 20

M = 100

def check(a, b, c):
    b[0] -= a[0]
    b[1] -= a[1]
    c[0] -= a[0]
    c[1] -= a[1]
    return b[0] * c[1] == b[1] * c[0]
    

points = list()
points.append([0, 0])

points.append([randrange(-M, M), randrange(-M, M)])

assert points[1] != [0, 0]


while len(points) < n:
    new_point = [randrange(-M, M), randrange(-M, M)]
    # for a in points:
    #     for b in points:
    #         if a != b:
    #             if check(a, b, new_point):
    #                 break
    #     else:
    #         continue
    #     break
    # else:
    points.append(new_point)


for point in points:
    print(point)