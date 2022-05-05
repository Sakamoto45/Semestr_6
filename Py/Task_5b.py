import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
fig = plt.figure(figsize=(4,4))
ax = fig.add_subplot(111, projection='3d')
import random
import numpy as np

dim = 3

def MultivariateNormalDistribution(n = dim, mean = np.zeros(dim), cov = np.identity(dim)):
    assert cov.shape == (n, n)
    assert mean.shape == (n,)
    A = np.linalg.cholesky(cov)
    return A @ np.random.normal(0, 1, n) + mean

def plot_shere():
    sample = np.empty((0, dim))

    for i in range(10000):
        vector = MultivariateNormalDistribution()
        
        
        vector = vector / np.linalg.norm(vector) * pow(random.uniform(0, 1), 1/dim)
        sample = np.append(sample, [vector], axis = 0)

    ax.scatter3D(sample[:,0], sample[:,1], sample[:,2], alpha = 0.1)
    plt.show()

def plot_distr():
    mean = np.array([4, 4, 4])
    cov = np.array([[2, -1, 0],
                    [-1, 2, -1],
                    [0, -1, 2]])
    sample = np.empty((0, dim))
    for i in range(10000):
        sample = np.append(sample, [MultivariateNormalDistribution(n = 3, mean = mean, cov = cov)], axis = 0)

    print(np.cov(sample.T))

    ax.scatter3D(sample[:,0], sample[:,1], sample[:,2], alpha = 0.1)
    plt.show()

plot_shere()
# plot_distr()
