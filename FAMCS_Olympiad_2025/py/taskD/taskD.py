d = [0 for i in range(26)]
for i in range(0,26, 2):
    d[i] = i+1
    d[i+1] = i

base = ord('a')
def f(message):
    for i in range(len(message)):
        message[i] = chr(d[ord(message[i]) - base] + base)
    return message

t = int(input())
for i in range(t):
    message = input()
    print(f(message))