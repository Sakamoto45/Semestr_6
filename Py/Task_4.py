import fileinput
import math
from scipy.stats import chisquare

def poisson(cycle_length, shuffle_length, sample_size):
    l = 1 / cycle_length
    density = [round(sample_size * l**k * math.exp(-l) / math.factorial(k)) for k in range(shuffle_length // cycle_length + 1)]

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
    print(groupped_obs)
    print(groupped_exp)
    return(chisquare(groupped_obs, f_exp=groupped_exp))



cycle_length_freq = [list(map(int, line.split())) + [0] for line in fileinput.input(files ='Py/cycle_length_test.txt')]

shuffle_length = len(cycle_length_freq)
sample_size = sum(cycle_length_freq[0])


for i in range(10):
    print(group_chisquare(cycle_length_freq[i], poisson(i + 1, shuffle_length, sample_size)))

    # print()
    # print(expected_freq)
    




# print()




# position_distribution_freq = [int(line) for line in fileinput.input(files ='Py/position_distribution_test.txt')]
