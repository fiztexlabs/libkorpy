import numpy as np
import matplotlib.pyplot as plt

plt.figure()
plt.ion()
# plt.show()
def korsar_mt(a):
    plt.scatter(a, a)
    plt.pause(0.01)
    plt.draw()
    return [0]
    # print(a[0],a[1])
    # return np.array([a[0] + a[1], 1])