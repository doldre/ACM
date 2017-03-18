from datetime import datetime
from datetime import timedelta
table = [[], []]
table[0] = [
    1972, 1981, 1982, 1983, 1985, 1992, 1993, 1994, 1997, 2012, 2015
]
table[1] = [
    1972, 1973, 1974, 1975, 1976, 1977, 1978, 1979, 1987, 1989, 1990, 
    1995, 1998,2005, 2008, 2016
]

times = [None, None]
times[0] = '06-30 23:59:59'
times[1] = '12-31 23:59:59'

a = raw_input()
b = raw_input()
add_a = timedelta(seconds=0)
add_b = timedelta(seconds=0)
if a[-2:] == '60':
    a = a[:-2] + '59'
    add_a = timedelta(seconds=1)
if b[-2:] == '60':
    b = b[:-2] + '59'
    add_b = timedelta(seconds=1)

timea = datetime.strptime(a.strip(), '%Y-%m-%d %H:%M:%S')
timeb = datetime.strptime(b.strip(), '%Y-%m-%d %H:%M:%S')
timea += add_a
timeb += add_b
res = (timeb - timea).seconds + (timeb - timea).days * 24 * 3600L
for _ in range(2):
    for y in table[_]:
            s = ('%d-' % y) + times[_]
            time = datetime.strptime(s, '%Y-%m-%d %H:%M:%S')
            if time >= timea and time < timeb:
                res += 1
            if time == timeb and add_b == timedelta(seconds=1):
                res -=1
            if time == timea and add_a == timedelta(seconds=1):
                res -=1
print(res)
