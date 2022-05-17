import fileinput
import math
from scipy.stats import chisquare
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np


def poisson(cycle_length, shuffle_length, sample_size):
    l = 1 / cycle_length
    density = [sample_size * math.exp(-l)]
    for k in range(1, shuffle_length // cycle_length + 1):
        density.append(density[-1] * l / k)
    density = [round(elem) for elem in density]
    density.append(sample_size - sum(density))
    return(density)

def group_chisquare(obs_freq, exp_freq):
    groupped_exp = [0]
    groupped_obs = [0]
    for j in range(len(exp_freq)):
        if groupped_exp[-1] < 5:
            groupped_exp[-1] += exp_freq[j]
            groupped_obs[-1] += obs_freq[j]
        else:
            groupped_exp.append(exp_freq[j])
            groupped_obs.append(obs_freq[j])
    if groupped_exp[-1] < 5:
        groupped_exp.append(groupped_exp.pop() + groupped_exp.pop())
        groupped_obs.append(groupped_obs.pop() + groupped_obs.pop())
    # print(obs_freq)
    # print(exp_freq)
    # print(groupped_obs)
    # print(groupped_exp)
    return(chisquare(groupped_obs, f_exp=groupped_exp))


def cycle_length_test(subplt):
    cycle_length_freq = [list(map(int, line.split())) + [0] for line in fileinput.input(files ='Py/cycle_length_test.txt')]

    shuffle_length = len(cycle_length_freq)
    sample_size = sum(cycle_length_freq[0])

    p_value = [group_chisquare(cycle_length_freq[i], poisson(i + 1, shuffle_length, sample_size))[1] for i in range(shuffle_length)]

    x = np.linspace(0, 1, shuffle_length)

    colors = cm.rainbow(x)

    p_value, colors = zip(*sorted(list(zip(p_value, colors)), key=lambda tup: tup[0]))

    subplt.scatter(x, p_value, marker='o', color=colors, s=1)
    subplt.set_title("Cycle length test")

def position_distribution_test(subplt):
    position_distribution_freq = [list(map(int, line.split())) for line in fileinput.input(files ='Py/position_distribution_test.txt')]

    shuffle_length = len(position_distribution_freq)
    sample_size = sum(position_distribution_freq[0])

    p_value = [chisquare(position_distribution_freq[i])[1] for i in range(shuffle_length)]

    x = np.linspace(0, 1, shuffle_length)

    colors = cm.rainbow(x)

    p_value, colors = zip(*sorted(list(zip(p_value, colors)), key=lambda tup: tup[0]))

    subplt.scatter(x, p_value, marker='o', color=colors, s=1)
    subplt.set_title("Position distribution test")



figure, axis = plt.subplots(2, 1)

cycle_length_test(axis[0])

position_distribution_test(axis[1])

plt.show()



# plt.scatter([i / shuffle_length for i in range(shuffle_length)], p_value, marker='o', s=1)



# plot()

# for i in range(50):
#     print(group_chisquare(cycle_length_freq[i], poisson(i + 1, shuffle_length, sample_size)))

    # print()
    # print(expected_freq)
    
