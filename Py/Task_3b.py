import matplotlib.pyplot as plt
import numpy as np
import fileinput
import math
import random

def isLeftTurn(points):
    return(np.cross(np.subtract(points[1], points[0]), np.subtract(points[2], points[1]))>0)

def isInTriangle(triangle, points):
    for point in points:
        s1 = (triangle[1][0] - point[0]) * (triangle[2][1] - triangle[1][1]) - (triangle[2][0] - triangle[1][0]) * (triangle[1][1] - point[1])
        s2 = (triangle[2][0] - point[0]) * (triangle[0][1] - triangle[2][1]) - (triangle[0][0] - triangle[2][0]) * (triangle[2][1] - point[1])
        s3 = (triangle[0][0] - point[0]) * (triangle[1][1] - triangle[0][1]) - (triangle[1][0] - triangle[0][0]) * (triangle[0][1] - point[1])
        if (s1 > 0 and s2 > 0 and s3 > 0) or (s1 < 0 and s2 < 0 and s3 < 0):
            return(True)
    return(False)
    

def triangulate(polygon):
    triangles = list()
    while (len(polygon) > 3):
        n = len(polygon)
        for i in range(n):
            triangle = [polygon[j%n] for j in range(i-1, i+2)]
            if (isLeftTurn(triangle)):
                if isInTriangle(triangle, [polygon[j] for j in range(n) if (j-i+1)%n > 2]):
                    continue
                triangles.append(triangle)
                del polygon[i]
                break
    triangles.append(polygon)
    return(triangles)

def plotPolygon(polygon):
    polygon.append(polygon[0])
    pol_x, pol_y = zip(*polygon)
    plt.plot(pol_x, pol_y)

def area(triangle):
    return(abs(np.cross(np.subtract(triangle[1], triangle[0]), np.subtract(triangle[2], triangle[0])))/2)

def TriangleRandom(triangle):
    a = random.uniform(0, 1)
    b = random.uniform(0, 1)
    if a+b>1:
        a, b = 1-a, 1-b
    return(np.add(triangle[0], np.add(a*np.subtract(triangle[1], triangle[0]), b * np.subtract(triangle[2], triangle[0]))))




polygon = [list(map(float, line.split(","))) for line in fileinput.input(files ='polygon.txt')]



triangles = triangulate(polygon)


areas = [area(triangle) for triangle in triangles]

areassum = sum(areas)

areas = [area/areassum for area in areas]


randomPoints = [TriangleRandom(triangles[k]) for k in np.random.choice([i for i in range(len(triangles))], 1000, p=areas)]






plotPolygon(polygon)

for triangle in triangles:
    plotPolygon(triangle)
# plotPolygon(triangles[0])

x, y = zip(*randomPoints)

# plt.plot(x, y, 'o')

plt.show()

