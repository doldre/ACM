R=lambda:list(map(int, input().split()))
n, k = R()
A = R() 
B = R()
items = list(zip(A, B))
items = sorted(items, key=lambda x: x[0] - x[1])
res = 0
for i in range(k):
    res += items[i][0]
for i in range(k, len(items)):
    res += min(items[i][0], items[i][1])
print(res)

