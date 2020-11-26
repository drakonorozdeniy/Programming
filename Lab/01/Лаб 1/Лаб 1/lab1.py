from tkinter import *
root =Tk()

label_1=Label(root,text="Имя")
label_2=Label(root,text="Пароль")

entry_1=Entry(root)
entry_2=Entry(root)



label_1.grid(row=0,colomn=0)
label_2.grid(row=1,colomn=0)

entry_1.grid(row=0,colomn=1)
entry_2.grid(row=1,colomn=1)

root.mainloop()
