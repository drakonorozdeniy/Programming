import requests 
from tkinter import *
import json
from tkinter.font import BOLD

r = requests.get('http://localhost:3000/')  
print(r.json())  

























#root = Tk ()
#root.title("Погода")
#root.geometry('134x189+200+100')

#one =Label(root,text="Симферополь\nоблачно ", width=20,  font=("Ubuntu",9,BOLD), bg="#ffba00",  fg="black")
#one.pack()
#two=Label(root, text ="2'C" , width=30,heigh=2 ,font=(" Droid Serif",40),bg="white", fg="black")
#two.pack()

#three=Label(root,text = "" , width=40, heigh=2, bg="#ffba00", )
#three.pack()

#root.mainloop()
