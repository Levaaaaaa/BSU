with open('squary.in', 'r') as fin:
    n, k = tuple(map(int, fin.read().split()))
sq = 1
while sq * sq <= n:
    sq += 1
sq -= 1
res = []
while sq > 0:
    res.append(n - (sq*sq))
    sq -= 1
box = [(-1, -1) for i in range(n+1)]
box[0] = (0, k)
for num in res:
    for i in range(n - num, -1, -1):
        if box[i][0] != -1 and box[i][1] > 0:
            if box[i+num][0] == -1 or box[i + num][1] > box[i][1] - 1:
                box[i + num] = [num, box[i][1] - 1]

with open('squary.out', 'w') as fout:
    if box[n][1] != 0:
        fout.write('NO')
    else :
        result = []
        cur = box[n][0]
        while cur > 0:
            result.append(str(cur))
            cur = box[cur][0]
        result = reversed(result)
        fout.write('YES\n')
        fout.write(' '.join(result))