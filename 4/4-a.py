import numpy as np
import matplotlib.pyplot as plt
from numpy import random
import japanize_matplotlib
from decimal import Decimal, ROUND_HALF_UP

plt.rcParams['mathtext.fontset'] = 'cm'

# A function that tosses a coin n times, records 1 when it comes up, 
# 0 when it comes down, and returns the record as a list.
def throwing_coin(n):
    a = []
    for i in range(n):
        r = random.random()
        if r < float(3/10):
            a.append(1)
        else: 
            a.append(0)
    return a

n = (2, 10, 40)
xbar_n = [0] * 1000
population_ave = 3 / 10

# Average and variance for each n
ave = []
var = []

for i in n:
    for j in range(1000):
        # Toss a coin n times and record the mean of the return value of throwing_coin 1000 times
        a = np.array(throwing_coin(i))
        xbar_n[j] = np.mean(a)

    ave.append(np.mean(xbar_n))
    var.append(np.var(xbar_n))

    # Standard deviation for n
    sigma = np.sqrt(3/10 * 7/10 / i)

    # Points of theoretical value of the normal distribution
    x = np.linspace(0, 1, 10000)
    y = 1 / np.sqrt(2*np.pi*sigma**2) * np.exp(-(x-population_ave)**2/(2*sigma**2))
    
    fig = plt.figure(figsize=(20, 10))

    # create the histogram
    ax1 = fig.add_subplot(1, 2, 1)
    ax1.set_xlabel(r'$\overline {Z}_{(n, m)} (m = 1, 2, \dots, 1000)$[-]', fontsize=16)
    ax1.set_ylabel('度数', fontsize=16)
    ax1.hist(xbar_n, bins=41, range=(0, 1))

    # create the standard diviation
    ax2 = fig.add_subplot(1, 2, 2, xlim=(0, 1))
    ax2.set_xlabel(r'$x$', fontsize=16)
    ax2.set_ylabel(r'$y=\frac{1}{\sqrt{2 \pi}\sigma}  e^{-(x-\mu)^2 /2 \sigma^2}$', fontsize=16)
    ax2.plot(x, y)

    fig.savefig('4-a' + 'ver' + str(i) + '.png', bbox_inches='tight', pad_inches=0.05)

# Write mean, variance and mean of experimental values and theoretical values of variance for each n in csv
with open('4-a.csv', mode='w') as f:
    f.write('n, 平均, 平均の理論値, 分散, 分散の理論値\n')
    for i in range(len(n)):
        f.write(str(n[i]) + ','\
            + str(Decimal(str(ave[i])).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + ','\
            + str(Decimal(str(population_ave)).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + ','\
            + str(Decimal(str(var[i])).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + ','\
            + str(Decimal(str(3/10*7/10/n[i])).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + '\n')