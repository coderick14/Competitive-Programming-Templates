n = input()

for i in xrange(n):
	s = raw_input().split()
	st = [x[0].capitalize() + '.' for x in s[:-1]]
	st += [s[-1].title()]
	print " ".join(st)

