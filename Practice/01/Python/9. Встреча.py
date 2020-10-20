s=0
for i in range (2):
    n=s 
    x=input()
    p=len(x)
    if p==4:
        b=x[0:1]
        l=x[2:4]
        s=((int(b))*60)+(int(l))
    else:
        b=x[0:2]
        l=x[3:5]
        s=((int(b))*60)+(int(l))
if (s-n)<=15 :
    print("Встреча состоиться")
else :
    print("Встреча не состоиться")
    
    
    

