cw = ['v','<','^','>']
ccw = ['v','>','^','<']

s,e = raw_input().split()
n = input()
n = n%4
icw, iccw = cw.index(s), ccw.index(s)
ecw, eccw = cw[(icw+n)%4], ccw[(iccw+n)%4]

if ecw == e and eccw == e:
	print "undefined"
elif eccw == e:
	print "ccw"
elif ecw == e:
	print "cw"
else:
	print "undefined"