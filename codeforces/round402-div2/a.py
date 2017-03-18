n = int(input())
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))
s = 0
for i in range(1, 6):
    x = a.count(i)
    y = b.count(i)
    if not (x + y) % 2 == 0: exit(print(-1))
    else: s += abs(x - y) // 2
print(s // 2)
