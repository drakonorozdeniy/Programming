import requests 
from tkinter import *
import json
from tkinter.font import BOLD
r = requests.get('http://localhost:3000/raw')
f=r.json()
a=f[0]["description"].encode('l1').decode()
b=str(f[0]["temp"])


root = Tk ()
root.title("Погода")
root.geometry('134x189+200+100')

one =Label(root,text="Симферополь\n"+a, width=40,  font=("Ubuntu",7,BOLD), bg="#ffba00",  fg="black")
one.pack()
two=Label(root, text =b+"°C" , width=30,heigh=2 ,font=(" Droid Serif",40),bg="white", fg="black")
two.pack()

three=Label(root,text = "" , width=40, heigh=2, bg="#ffba00", )
three.pack()

root.mainloop()





