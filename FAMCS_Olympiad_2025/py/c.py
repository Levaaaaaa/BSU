nums = ['6']
a = 6
c = 0
res = 0
while(res!=6):
    res = a * 3 + c
    sec = res % 10
    c = (res - sec) / 10
    a = sec
    nums.append(str(int(sec)))
print("".join(nums[::-1])[1::])



#print(2068965517241379310344827586 * 3)
