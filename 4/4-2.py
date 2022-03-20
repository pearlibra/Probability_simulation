import numpy as np
import matplotlib.pyplot as plt
from numpy import random
import japanize_matplotlib
from decimal import Decimal, ROUND_HALF_UP

plt.rcParams['mathtext.fontset'] = 'cm'

# function of throw dice n times and return a list of dice
def throwing_dice(n):
    a = []
    for i in range(n):
        r = random.random()
        if r < float(1/6):
            a.append(1)
        elif r < float(2/6):
            a.append(2)
        elif r < float(3/6):
            a.append(3)
        elif r < float(4/6):
            a.append(4)
        elif r < float(5/6):
            a.append(5)
        else:
            a.append(6)
    return a

n = (2, 4, 10)
ybar_n = [0] * 1000
population_ave = 7 / 2

# Average and variance for each n
ave = []
var = []

for i in n:
    # Throw the dice n times and record the average of the results 1000 times
    for j in range(1000):
        a = np.array(throwing_dice(i))
        ybar_n[j] = np.mean(a)

    ave.append(np.mean(ybar_n))
    var.append(np.var(ybar_n))

    # standard diviation for n
    sigma = np.sqrt((35/12) / i)

    # Points of theoretical value of the normal distribution
    x = np.linspace(1, 6, 10000)
    y = 1 / np.sqrt(2*np.pi*sigma**2) * np.exp(-(x-population_ave)**2/(2*sigma**2))

    fig = plt.figure(figsize=(20, 10))
    
    # create the histgram
    ax1 = fig.add_subplot(1, 2, 1)
    ax1.set_xlabel(r'$\overline {Y}_{(n, m)} (m = 1, 2, \dots, 1000)$[-]', fontsize=16)
    ax1.set_ylabel('度数', fontsize=16)
    ax1.hist(ybar_n, bins=51, range=(1, 6))

    # create the standard diviation
    ax2 = fig.add_subplot(1, 2, 2, xlim=(1, 6))
    ax2.set_xlabel(r'$x$', fontsize=16)
    ax2.set_ylabel(r'$y=\frac{1}{\sqrt{2 \pi}\sigma}  e^{-(x-\mu)^2 /2 \sigma^2}$', fontsize=16)
    ax2.plot(x, y)

    fig.savefig('4-2' + 'ver' + str(i) + '.png', bbox_inches='tight', pad_inches=0.05)

# write average, variance and theoretical values of average, variance for each n in csv
with open('4-2.csv', mode='w') as f:
    f.write('n, 平均, 平均の理論値, 分散, 分散の理論値\n')
    for i in range(len(n)):
        f.write(str(n[i]) + ','\
            + str(Decimal(str(ave[i])).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + ','\
            + str(Decimal(str(population_ave)).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + ','\
            + str(Decimal(str(var[i])).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + ','\
            + str(Decimal(str(str(35/12 / n[i]))).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + '\n')