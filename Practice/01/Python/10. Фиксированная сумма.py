import math
n=int(input())
k=0
for i in range (2,((int(math.sqrt(n)))+1)):
    b=n
    if b%i==0 :
        k=k+1
if k==0 :
    print('Простое ')
else :
    print('Составное ')
    

