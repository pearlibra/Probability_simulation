import numpy as np
import matplotlib.pyplot as plt
from numpy.lib.scimath import sqrt
import japanize_matplotlib
from decimal import Decimal, ROUND_HALF_UP

plt.rcParams['mathtext.fontset'] = 'cm'

n = (2, 4, 10)
xbar_n = [0] * 1000
population_ave = 0

# Average and variance for each n
ave = []
var = []

for i in n:
    for j in range(1000):
        # Generate 1000 numbers that follow a normal distribution.
        a = np.random.normal(loc=0.0, scale=1.0, size=i)
        xbar_n[j] = np.mean(a)
    ave.append(np.mean(xbar_n))
    var.append(np.var(xbar_n))

    # Standard deviation for n
    sigma = 1 / np.sqrt(i)

    # Points of theoretical value of the normal distribution
    x = np.linspace(-3, 3, 10000)
    y = 1 / np.sqrt(2*np.pi*sigma**2) * np.exp(-(x-population_ave)**2/(2*sigma**2))

    fig = plt.figure(figsize=(20, 10))
    # create a histogram
    ax1 = fig.add_subplot(1, 2, 1)
    ax1.set_xlabel(r'$\overline {X}_{(n, m)} (m = 1, 2, \dots, 1000)$[-]', fontsize=16)
    ax1.set_ylabel('度数', fontsize=16)
    ax1.hist(xbar_n, bins=200, range=(-3, 3))

    # create a normal distribution
    ax2 = fig.add_subplot(1, 2, 2, xlim=(-3, 3))
    ax2.set_xlabel(r'$x$', fontsize=16)
    ax2.set_ylabel(r'$y=\frac{1}{\sqrt{2 \pi}\sigma}  e^{-(x-\mu)^2 /2 \sigma^2}$', fontsize=16)
    ax2.plot(x, y)

    fig.savefig('4-1' + 'ver' + str(i) + '.png', bbox_inches='tight', pad_inches=0.05)

# write average, variance and theoretical values of average, variance for each n in csv
with open('4-1.csv', mode='w') as f:
    f.write('n, 平均, 平均の理論値, 分散, 分散の理論値\n')
    for i in range(len(n)):
        f.write(str(n[i]) + ','\
            + str(Decimal(str(ave[i])).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + ','\
            + str(Decimal(str(population_ave)).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + ','\
            + str(Decimal(str(var[i])).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + ','\
            + str(Decimal(str(1/n[i])).quantize(Decimal('0.001'), rounding=ROUND_HALF_UP)) + '\n')


    

    
