
from tkinter import *
def submit():
    lang=[]
    if c1.get()==1:
        lang.append("English")
    if c2.get()==1:
        lang.append("Hindi")
    if c3.get()==1:
        lang.append("French")
    if len(lang)>0:
        print(",".join(lang))
    else:
        print("no language selected !!...")
    
root=Tk()
root.title("check box")
root.geometry("250x200")
c1=IntVar()
c1.set(0)
c2=IntVar()
c2.set(0)
c3=IntVar()
c3.set(0)
ch1=Checkbutton(root,text="English",variable=c1)
ch1.pack()
ch2=Checkbutton(root,text="hindi",variable=c2)
ch2.pack()
ch3=Checkbutton(root,text="French",variable=c3)
ch3.pack()
but=Button(root,text="submit",command=submit)
but.pack()#place
root.mainloop()
