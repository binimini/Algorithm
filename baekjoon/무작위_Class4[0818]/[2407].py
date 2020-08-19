x,y  = input().split()
x = int(x)
y = int(y)
if (y>x-y):
    y = x-y
result = 1
for i in range(y):
    result*=x-i
for i in range(1,y+1):
    result/=i
print(int(result))