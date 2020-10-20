import math 
a=float(input())
b=float(input())
c=float(input())
D=b**2-(4*a*c)
if a==0 and c!=0 and b!=0  :
    x=(-1*c)/b
    print('x=',int(x))
elif D>0 :
    x1=(-b+(math.sqrt(D)))/(2*a)
    x2=(-b-(math.sqrt(D)))/(2*a)
    print('x1 =',int(x1))
    print('x2 =',int(x2))
elif D==0 :
    x=-b/(2*a)
    print('x =',int(x))
elif D<0 :
    print('нет решений' )
    
