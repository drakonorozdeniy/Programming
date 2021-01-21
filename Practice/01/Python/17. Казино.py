m=37
numbers=[0]*m
red = 0
black = 0
a = 0
print(len(numbers))
array_red = [ 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 ]
array_black = [2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 ]
while (1):
    numb=int(input("Введите число\n"))
    if numb < 0 or numb > 36:
        break
    else:
         numbers[numb]+=1
         for color in range (18):
             if (numb == array_red[color]):
                 red = red + 1					
             elif (numb == array_black[color]):
                 black = black + 1
    for s in range(m):
        if (numbers[s] > a):
            a = numbers[s]			        
    for s in range(m):
        if (numbers[s] == a):
            print(s, end='')
    for s in range(m):
        if (numbers[s] == 0):
          print(s, end=' ')
    print("\n",red,black)
	
