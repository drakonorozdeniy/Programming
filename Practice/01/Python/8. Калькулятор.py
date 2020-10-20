x,o,y=input().split()
if o=='*':
    print(int(x)*int(y))
elif o=='/':
    if int(y)==0 :
        print("Делить на ноль нельзя")
    else :
        print(int(x)/int(y))
elif o=='+':
    print (int(x)+int(y))
elif o=='-':
    print (int(x)-int(y))
    

