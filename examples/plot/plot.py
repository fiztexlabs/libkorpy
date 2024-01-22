import matplotlib.pyplot as plt

class KorsarMT:
	plt.figure()
	
	def getResult(self, input):
			plt.scatter(input[0], input[1], color = 'red')
			plt.draw()
			plt.pause(0.01)
			
			return [0]