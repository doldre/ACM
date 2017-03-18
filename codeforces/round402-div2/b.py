n, k = input().strip().split()
k = int(k)
n = list(n)
cnt_zero = n.count('0')
res, cnt = 0, 0
n.reverse()
for c in n:
    if c == '0': cnt += 1
    else: res += 1
    if cnt == k: break
print(res if cnt == k else len(n) - 1)
