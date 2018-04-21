n = input()
a, b = 1, 2
for i in range(1,n):
	c = (b << 1) ^ a
	a = b
	b = c
print n
for i in range(n+1):
	x = 1 if (b & 1) else 0
	print x,
	b >>= 1
print
print n-1
for i in range(n):
	x = 1 if (a & 1) else 0
	print x,
	a >>= 1