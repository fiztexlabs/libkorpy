import numpy as np
# np.set_printoptions(linewidth=500)

class KorsarMT:
	CH1 = open("CH1.dat",'w')
	CH2 = open("CH2.dat",'w')
	CH3 = open("CH3.dat",'w')
	CH4 = open("CH4.dat",'w')
	CH5 = open("CH5.dat",'w')
	CH6 = open("CH6.dat",'w')
	CH7 = open("CH7.dat",'w')
	CH8 = open("CH8.dat",'w')
	CH9 = open("CH9.dat",'w')
	CH10 = open("CH10.dat",'w')
	
	def getResult(self, input):
			input = np.array(input)
			
			np.savetxt(self.CH1, input[1:150], newline='\t', fmt='%4f')
			self.CH1.write('\n')
			
			np.savetxt(self.CH2, input[151:301], newline='\t', fmt='%4f')
			self.CH2.write('\n')
			
			np.savetxt(self.CH3, input[302:452], newline='\t', fmt='%4f')
			self.CH3.write('\n')
			
			np.savetxt(self.CH4, input[453:603], newline='\t', fmt='%4f')
			self.CH4.write('\n')
			
			np.savetxt(self.CH5, input[604:754], newline='\t', fmt='%4f')
			self.CH5.write('\n')
			
			np.savetxt(self.CH6, input[755:905], newline='\t', fmt='%4f')
			self.CH6.write('\n')
			
			np.savetxt(self.CH7, input[906:1056], newline='\t', fmt='%4f')
			self.CH7.write('\n')
			
			np.savetxt(self.CH8, input[1057:1207], newline='\t', fmt='%4f')
			self.CH8.write('\n')
			
			np.savetxt(self.CH9, input[1208:1358], newline='\t', fmt='%4f')
			self.CH9.write('\n')
			
			np.savetxt(self.CH10, input[1359:1509], newline='\t', fmt='%4f')
			self.CH10.write('\n')
			
			return [0]