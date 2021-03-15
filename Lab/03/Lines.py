from tkinter import *
from tkinter import font

from PIL import Image, ImageTk
 
 
root = Tk()
root.geometry("800x650")
tileset = Image.open("cell-bgr.png")
img = ImageTk.PhotoImage(tileset.crop((1, 0, 67, 66)))

background_image=ImageTk.PhotoImage(file="page-bgr.png")
background_label=Label(root,image=background_image).pack()
background_label.place(x=100,y=0,relwidth=1, relheight=1)

k=30
for i in range(9):
    for j in range(9):
        lbl = Label(root, image = img, borderwidth=0)
        lbl.grid(row=i,column=j, padx=1, pady=1)
        lbl.place(x=k,y=20+(65*j))
    k=k+65
    y=0

     

root.mainloop()

 

