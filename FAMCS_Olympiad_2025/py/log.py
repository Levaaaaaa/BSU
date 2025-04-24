# import numpy as np
# import math
# print(math.log(39, 3))


# def res():
#     x = input()
#     len_x = len(x)
#     for i in range(1, len_x):
#         k = len_x - i
#         n = k // 2
#         for j in range(1, n+1):
#             tmp = len_x - i - j - max(i, j)
#             if  tmp < 2 and tmp >= 0:
#                 if (int(x[:i]) + int(x[i:i+j]) == int(x[i+j::])):
#                     print(f"{x[:i]}+{x[i:j+i]}={x[j+i::]}")
#                     return
# res()

with open('lucky.in', 'r') as f:
    k = int(f.read().strip())
    a = 3
    dct = {1:'1', 2:'3', 3:'7'}
    answer = []
    if k < 4:
        answer.append(dct[k])
    else:
        t = 1
        while (k - a >= 0):
            k -= a
            a *= 3
            t +=1
        z = 3.0
        for i in range(t-1, -1, -1):
            z_1 = z ** i
            tr = k % z_1
            s = k // z_1
            s += (tr != 0)
            if k % z_1 == 0:
                k //= z_1 
                k += 1
            else:
                if s > 1:
                    k //= z_1
            answer.append(dct[s])

with open('lucky.out', 'w') as f_out:
    f_out.write(''.join(answer))
