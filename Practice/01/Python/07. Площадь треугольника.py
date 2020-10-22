import math 
print('С каким способом ввода вы бы желали поработать:\n1-ввод параметров треугольника через длины сторон\n2-ввод параметров через координаты вершин')
z=int(input())
if z==1 :
    print('Вы выбрали ввод через длины сторон  a,b,c ')
    a=int(input())
    b=int(input())
    c=int(input())
    if (a+b)<c :
        print('Введите верные числовые значения,\nсумма двух сторон обязана быть больше третьей')
    else :
        p=(a+b+c)/2
        S=math.sqrt(p*(p-a)*(p-b)*(p-c))
        print('S =',int(S))
else :
    print('Вы выбрали ввод через координаты вершин A,B,C ')
    x1, y1 = map(int, input().split())
    x2,y2 = map(int, input().split())
    x3,y3 = map(int, input().split())
    a1=math.sqrt(((y2-y1)**2)+((x2-x1)**2))
    b1=math.sqrt(((y3-y2)**2)+((x3-x2)**2))
    c1=math.sqrt(((y1-y3)**2)+((x1-x3)**2))
    print(a1,b1,c1)
    if (a1+b1)<c1:
        print('Введите верные числовые значения,\nсумма двух сторон обязана быть больше третьей')
    else :
        S=0.5*(math.fabs(x2*y3-x3*y2))
        print('S  =',int(S))
        

    
    

    
