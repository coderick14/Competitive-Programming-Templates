n,m = raw_input().split()
n,m=int(n),int(m)
mp = {}
for i in range(n):
	name, ip= raw_input().split()
	mp[ip] = name
for i in range(m):
	command, ip = raw_input().split()
	ip = ip[:-1]
	print "%s %s; #%s" % (command, ip, mp[ip])