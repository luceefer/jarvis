from tkinter import *
from tkinter import messagebox
def show():
    text=inp.get().strip()
    var.set(inp.get())
    if len(text)==0:
        messagebox.showerror("invalid data","you haven't entered a string")
    else:
        var.set(text)
    inp.delete(0,END)
   
root=Tk()
root.title("change Lable")
root.geometry("250x200")
var=StringVar()
var.set("My label")
lab=Label(root,text="My Lable",textvariable=var)
lab.pack()
inp=Entry(root,bd=5)
inp.pack()
but=Button(root,text="Show",command=show)
but.pack()
inp.focus() 
root.mainloop()
