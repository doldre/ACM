def judge(t, p):
    j = 0
    for ch in p:
        while j < len(t) and t[j] != ch: j += 1
        if j >= len(t): return False
        j += 1
    return True

def generate(t, a, n):
    res = list(t)
    for i in range(n):
        res[a[i] - 1] = '#'
    res = "".join(res)
    return res.replace('#', '')

t = input()
p = input()
a = list(map(int, input().split()))

l, r = 0, len(t) - len(p) + 1

while l < r - 1:
    m = (l + r) // 2
    tmp = generate(t, a, m)
    if judge(tmp, p):
        l = m
    else: r = m 

print(l)
