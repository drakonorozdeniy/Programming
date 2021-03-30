size=int(input())
first=int(input())
step=int(input())

def create (size, first=0,step=0) :
    arr =[1]*size
    for i in range (size) :
        arr[i]=first
        first=first+step
    return arr

def sort (arr,size) :
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
    return arr

def to_print (arr,size):
    print('[', sep='', end='')
    for i in range(size - 1):
        print(arr[i], ', ', sep='', end='')
    print(arr[size-1] , ']', sep='', end='')
    return arr

arr=create(size,first,step)
sort(arr,size)
to_print(arr,size)
