n = input()
r = input()
r = min(r,n-r)
ans = 1
for i in range(r):
    ans = ans * (n-i)/(i+1)
print ans
