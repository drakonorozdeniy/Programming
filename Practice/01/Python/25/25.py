import random
n=int(input())
A= [] 
a=[]
m=1
for i in range(1):
    row = input().split()
    for i in range(len(row)):
        row[i] = int(row[i])
        a.append(row[i])
    A.append(row)
def Bozosort(a,sortirovka =True) :
    exit = False
    if sortirovka:
        while(exit!=True ) :
            exit =True
            m=len(a)
            i = random.choice(a)
            k = random.choice(a)
            if (i<=k and a.index(i) >a.index(k)) or (k<=i and  a.index(k)>a.index(i)):
                a[a.index(i)],a[a.index(k)]=a[a.index(k)],a[a.index(i)]
            for  j in range (m-1) :
                if a[j]>a[j+1] :
                    exit=False
    else :
        while(exit!=True ) :
            exit =True
            m = len(a)
            i = random.choice(a)
            k = random.choice(a)
            if (i<=k and a.index(i) <a.index(k)) or (k<=i and  a.index(k)<a.index(i)):
                a[a.index(i)],a[a.index(k)]=a[a.index(k)],a[a.index(i)]
            for  j in range (m-1) :
                if a[j]<a[j+1] :
                     exit=False
    return a
def Bozosort_3(a,sortirovka =True) :
    exit=False
    if sortirovka:
        while(exit!=True ) :
            exit =True
            m=len(a[0])
            i = random.choice(a[0])
            k = random.choice(a[0])
            if (i<=k and (a[0].index(i) >a[0].index(k))) or (k<=i and  (a[0].index(k)>a[0].index(i))):
                a[0][a[0].index(i)],a[0][a[0].index(k)]=a[0][a[0].index(k)],a[0][a[0].index(i)]
            for  j in range (m-1) :
                if a[0][j]>a[0][j+1] :
                    exit=False
    else :
        while(exit!=True ) :
            exit =True
            m = len(a[0])
            i = random.choice(a[0])
            k = random.choice(a[0])
            if (i<=k and a[0].index(i) <a[0].index(k)) or (k<=i and  a[0].index(k)<a[0].index(i)):
                a[0][a[0].index(i)],a[0][a[0].index(k)]=a[0][a[0].index(k)],a[0][a[0].index(i)]
            for  j in range (m-1) :
                if a[0][j]<a[0][j+1] :
                    exit=False
    return (a[0])

def Bozosort_2(A,B,C,sortirovka =True):
    array=[]
    array.append(A)
    array.append(B)
    array.append(C)
    Bozosort(array,sortirovka)
    return array

y=Bozosort_2(a[0],a[1],a[2])
p=Bozosort_2(a[0],a[1],a[2],False)
print(" ".join(map(str,Bozosort(a))))
print(" ".join(map(str,Bozosort(a,False))))
print(" ".join(map(str,Bozosort_3(A))))
print(" ".join(map(str,Bozosort_3(A,False))))
print(" ".join(map(str,y)))
print(" ".join(map(str,p)))




        
        
        
