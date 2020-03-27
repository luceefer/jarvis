"""
from tkinter import *
from tkinter import messagebox
def place():
    pass
root=Tk()
root.title("calculater")
root.geometry("225x300")
root.resizable(0,0)
frame1=Frame(root)
b7=Button(frame1,text="7",font=("Arial",15,"bold"),command=place)
b7.grid(row=0,column=0)
b8=Button(root,text="8",command=place)
b8.grid(row=0,column=1)
b9=Button(root,text="9",command=place)
b9.grid(row=0,column=2)
b10=Button(root,text="+",command=place)
b10.grid(row=0,column=3)
b4=Button(root,text="4",command=place)
b4.grid(row=1,column=0)
b5=Button(root,text="5",command=place)
b5.grid(row=1,column=1)
b6=Button(root,text="6",command=place)
b6.grid(row=1,column=2)
b70=Button(root,text="-",command=place)
b70.grid(row=1,column=3)


root.mainloop()


"""

from tkinter import *
#from tkinter import messagebox
def place(val):
    if val=="=":
        try:
            var.set(eval(var.get()))
        except:
            messagebox.showerror("incorect data","please reevaluate your exprestion")
    elif val=="<--":
        var.set(var.get()[:-1]) # for delecting value
    else:
        var.set(var.get()+val)
root=Tk()
root.title("calculater")
root.geometry("225x300")
var=StringVar()
#root.resizable(0,0)
frame=Frame(root)
inp=Entry(frame,textvariable=var,font=("Arial",12,"bold"),bd=6)
inp.pack(fill=BOTH,expand=YES)
frame.pack(fill=BOTH,expand=YES)
frame1=Frame(root)

b7=Button(frame1,text="7",font=("Calibri",15,"bold"),command=lambda :place("7"))
b7.pack(side=LEFT,fill=BOTH,expand=YES)
b8=Button(frame1,text="8",font=("Arial",15,"bold"),command=lambda :place("8"))
b8.pack(side=LEFT,fill=BOTH,expand=YES)
b9=Button(frame1,text="9",font=("Arial",15,"bold"),command=lambda :place("9"))
b9.pack(side=LEFT,fill=BOTH,expand=YES)
b70=Button(frame1,text="+",font=("Arial",15,"bold"),command=lambda :place("+"))
b70.pack(side=LEFT,fill=BOTH,expand=YES)
frame1.pack(fill=BOTH,expand=YES)
frame2=Frame(root)
b4=Button(frame2,text="4",font=("Arial",15,"bold"),command=lambda :place("4"))
b4.pack(side=LEFT,fill=BOTH,expand=YES)
b5=Button(frame2,text="5",font=("Arial",15,"bold"),command=lambda :place("5"))
b5.pack(side=LEFT,fill=BOTH,expand=YES)
b6=Button(frame2,text="6",font=("Arial",15,"bold"),command=lambda :place("6"))
b6.pack(side=LEFT,fill=BOTH,expand=YES)
b56=Button(frame2,text="-",font=("Arial",15,"bold"),command=lambda :place("-"))
b56.pack(side=LEFT,fill=BOTH,expand=YES)
frame2.pack(fill=BOTH,expand=YES)
frame3=Frame(root)
b1=Button(frame3,text="1",font=("Arial",15,"bold"),command=lambda :place("1"))
b1.pack(side=LEFT,fill=BOTH,expand=YES)
b2=Button(frame3,text="2",font=("Arial",15,"bold"),command=lambda :place("2"))
b2.pack(side=LEFT,fill=BOTH,expand=YES)
b3=Button(frame3,text="3",font=("Arial",15,"bold"),command=lambda :place("3"))
b3.pack(side=LEFT,fill=BOTH,expand=YES)
b73=Button(frame3,text="/",font=("Arial",15,"bold"),command=lambda :place("/"))
b73.pack(side=LEFT,fill=BOTH,expand=YES)
frame3.pack(fill=BOTH,expand=YES)
frame4=Frame(root)
b77=Button(frame4,text=".",font=("Arial",15,"bold"),command=lambda :place("."))
b77.pack(side=LEFT,fill=BOTH,expand=YES)
b87=Button(frame4,text="0",font=("Arial",15,"bold"),command=lambda :place("0"))
b87.pack(side=LEFT,fill=BOTH,expand=YES)
b97=Button(frame4,text="*",font=("Arial",15,"bold"),command=lambda :place("*"))
b97.pack(side=LEFT,fill=BOTH,expand=YES)
b707=Button(frame4,text="=",font=("Arial",15,"bold"),command=lambda :place("="))
b707.pack(side=LEFT,fill=BOTH,expand=YES)
b708=Button(frame4,text="<--",font=("Arial",15,"bold"),command=lambda :place("<--"))
b708.pack(side=LEFT,fill=BOTH,expand=YES)
frame4.pack(fill=BOTH,expand=YES)

root.mainloop()
