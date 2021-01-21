print("Введите длину пароля:")
lenght=int(input())
print("Введите символы")
simbols=str(input())
code = ['']
code_new = []
for i in range(lenght):
   for j in code:
      for k in simbols:
         code_new += [j + k]
   code = code_new
   code_new = []
for j, i in zip(code, range(len(code))):
   if (not all([k in j for k in simbols])):
      del code[i]
for i in range(len(code)):
    print(code[i],end=" ")

