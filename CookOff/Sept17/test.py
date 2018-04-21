def sublists(l):
    return [l[m:n + 1] for m in range(0, len(l)) for n in range(m, len(l))]
for n in range(1, 101):
    l = n / 2
    r = n / 2 if n % 2 else n / 2 - 1
    l = range(n - l, n + r + 1)
    subs = sublists(l)
    medsum = sum([sub[len(sub) / 2] if len(sub) %
                  2 else (sub[len(sub) / 2 - 1] + sub[len(sub) / 2]) / 2.0 for sub in subs])
    res = (medsum * 2.0) / (n * (n + 1))
    print res >= (n-1) and res <= (n+1)
