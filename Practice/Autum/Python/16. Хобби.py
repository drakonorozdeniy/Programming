n = int(input())
l = input().split()
b=[]
u=0
for i in range (n) :
    k=l[i][0:1]
    o=l[i][4:9]
    if k=='a' and o=='55661' :
        b.append(l[i])
        u+=1
if u==0 :
    print('-1')
print(' '.join(map(str, b)))
    
        
        
