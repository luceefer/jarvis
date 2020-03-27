from tkinter import *
def show():
    a=["Male","Female","Transgender"]
    lab.config(text="your gender :- " +a[r.get()-1])
root=Tk()
root.title("radio button")
root.geometry("250x200")
r=IntVar()
rb1=Radiobutton(root,text="Male",variable=r,value=1,command=show)
rb1.pack()
rb2=Radiobutton(root,text="FEMale",variable=r,value=2,command=show)
rb2.pack()
rb3=Radiobutton(root,text="Transgender",variable=r,value=3,command=show)
rb3.pack()
lab=Label(root)
lab.pack()
root.mainloop()
