n=int(input())
signals=[]
def sortirovka(a,n) :
    exit=False
    while (exit!=True) :
        exit=True
        for j in range (len(a)-1)  :
            if (a[j]<a[j+1]) :
                a[j],a[j+1] = a[j+1],a[j]
                exit= False
    return a

for i  in range (n) :
    b=int(input())
    if len(signals)!=5 :
        signals.append(b)
    elif len(signals)==5 and b<max(signals) :
        signals.remove(max(signals))
        signals.append(b)
    print(" ".join(map(str,sortirovka(signals,len(signals)))))


