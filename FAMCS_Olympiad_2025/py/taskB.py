def f(n):
    return n * (n-1) // 2

with open('camp.in', 'r') as fin:
    n, m = tuple(map(int, fin.read().split()))
    mx = f(n - m + 1)
    mn = (n % m) * f(n // m + 1) + (m - n % m) * f(n // m)
   
with open('camp.out', 'w') as fout:
    fout.write(str(int(mn)) + ' ' + str(int(mx)))