s,l1,r1,l2,r2= map(int,input().split())
m=s-l1
o=s-r1
if l2<=m<=r2 :
    print(l1,m )
elif l2<=o<=r2:
    print(5,o)
else :
    print('-1')
