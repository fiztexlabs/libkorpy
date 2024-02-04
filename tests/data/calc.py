import numpy as np
import matplotlib.pyplot as plt
plt.figure()
plt.xlabel("t, sec")
plt.ylabel("P, MPa")

class KorsarMT:
	k = []
	n = np.zeros(3)
	def getResult(self, a):
			self.k.append(10)
			plt.plot(self.n[0], self.n[1])
			plt.show()
			return self.k