import matplotlib.pyplot as plt
import numpy as np
import fileinput
import math
import random

def isLeftTurn(points):
    return(np.cross(points[1] - points[0], points[2] - points[1]) > 0)

def isInTriangle(triangle, points):
    for point in points:
        s1 = isLeftTurn([triangle[0], triangle[1], point])
        s2 = isLeftTurn([triangle[1], triangle[2], point])
        s3 = isLeftTurn([triangle[2], triangle[0], point])
        if (s1 == s2 and s2 == s3):
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
    return(abs(np.cross(triangle[1] - triangle[0], triangle[2] - triangle[0])) / 2)

def TriangleRandom(triangle):
    a = random.uniform(0, 1)
    b = random.uniform(0, 1)
    if a + b > 1:
        a, b = 1 - a, 1 - b
    return((1-a-b) * triangle[0] + a * triangle[1] + b * triangle[2])


polygon = [np.array(list(map(float, line.split(",")))) for line in fileinput.input(files ='Py/polygon.txt')]
triangles = triangulate(polygon)

areas = np.array(list(map(area, triangles)))
areas = areas / sum(areas)

randomPoints = [TriangleRandom(triangles[k]) for k in np.random.choice(len(triangles), 100, p=areas)]


for triangle in triangles:
    plotPolygon(triangle)

x, y = zip(*randomPoints)
plt.scatter(x, y, marker='o', s=1)

plt.show()