from tkinter import *
from tkinter import messagebox
import sqlite3 as sql
def setup():
    db=sql.connect("users.db")
    query="""CREATE TABLE IF NOT EXISTS USER(Name varchar(50),Email varchar(100) primary key,
                 Gender varchar(10),
                 Phone varchar(15),
                 Language varchar(50))"""
    cur=db.cursor()
    cur.execute(query)
    db.close()

def add_data():
    def save():
        db=sql.connect("users.db")
        cur=db.cursor()
        n=name.get()
        e=email.get()
        a=["Male","Female","Transgender"]
        g=a[gen.get()-1]
        p=phone.get()
        a=["English","Hindi","German"]
        lang=[]
        for i,ch in enumerate([c1,c2,c3]):
            if ch.get()==1:
                lang.append(a[i])
        query="""INSERT INTO USER VALUES(?,?,?,?,?)"""
        try:
            cur.execute(query,[n,e,g,p,','.join(lang)])
            db.commit()
            messagebox.showinfo("Registration Success","User Registered...")
            add.destroy()
        except:
            messagebox.showerror("Invalid Email","User Already Registered...")
            email.delete(0,END)
            email.focus()
        finally:    
            db.close()
        
        
    add = Toplevel()
    add.title("Add New Data ")
    add.geometry("400x400")

    #line 1
    frame = Frame(add)
    l1 = Label(frame,text="Name: ",font=("Arial",18,"bold"))
    l1.pack(side=LEFT)
    name = Entry(frame,bd=3,width=50,font=("Arial",18,"bold"))
    name.pack()

    frame.pack(padx = 10,pady = 15)

     #line 2
    frame1 = Frame(add)
    l2 = Label(frame1,text="Email: ",font=("Arial",18,"bold"))
    l2.pack(side=LEFT)
    email = Entry(frame1,bd=3,width=50,font=("Arial",18,"bold"))
    email.pack()

    frame1.pack(padx = 10,pady = 15)
    
    #line 3
    frame2 = Frame(add)
    l3 = Label(frame2,text="Gender: ",font=("Arial",18,"bold"))
    l3.pack(side=LEFT)
    gen = IntVar()
    rb1 = Radiobutton(frame2,text="Male ",font=("Arial",12,"bold"),variable=gen,value=1)
    rb1.pack(side=LEFT)
    rb2 = Radiobutton(frame2,text="Female ",font=("Arial",12,"bold"),variable=gen,value=2)
    rb2.pack(side=LEFT)
    rb3 = Radiobutton(frame2,text="Transgender ",font=("Arial",12,"bold"),variable=gen,value=3)
    rb3.pack(side=LEFT)

    frame2.pack(padx = 10,pady = 15)

     #line 4
    frame3 = Frame(add)
    l4 = Label(frame3,text="Phone: ",font=("Arial",18,"bold"))
    l4.pack(side=LEFT)
    phone = Entry(frame3,bd=3,width=50,font=("Arial",18,"bold"))
    phone.pack()

    frame3.pack(padx = 10,pady = 15)

    #line 5
    frame4 = Frame(add)
    l5 = Label(frame4,text="Lang: ",font=("Arial",18,"bold"))
    l5.pack(side=LEFT)
    c1 = IntVar()
    c1.set(0)
    ch1 = Checkbutton(frame4,text="English",font=("Arial",14,"bold"),variable=c1)
    ch1.pack(side=LEFT)
    c2 = IntVar()
    c2.set(0)
    ch2 = Checkbutton(frame4,text="Hindi",font=("Arial",14,"bold"),variable=c2)
    ch2.pack(side=LEFT)
    c3 = IntVar()
    c3.set(0)
    ch3 = Checkbutton(frame4,text="German",font=("Arial",14,"bold"),variable=c3)
    ch3.pack(side=LEFT)

    frame4.pack(padx = 10,pady = 15)

    save = Button(add,text="SAVE",font=("Arial",22,"bold"),command=save)
    save.pack()
    add.mainloop()

    
    
def show_data():
    show=Toplevel()
    show.title("Show Details")
    show.geometry("550x450")
    #line1
    frame=Frame(show)
    lab1=Label(frame,text="Enter Email:",font=("Arial",18,"bold"))
    lab1.pack(side=LEFT)
    email=Entry(frame,bd=3,font=("Arial",18,"bold"),width=20)
    email.pack(side=LEFT)
    check=Button(frame,text="Fetch",font=("Arial",17,"bold"))
    check.pack(side=LEFT,padx=5)
    frame.pack(padx=10,pady=15)

    #line2
    frame1=Frame(show)
    name=Label(frame1,text="Name:",font=("Arial",18,"bold"))
    name.pack()
    em=Label(frame1,text="Email:",font=("Arial",18,"bold"))
    em.pack()
    gen=Label(frame1,text="Gender:",font=("Arial",18,"bold"))
    gen.pack()
    phone=Label(frame1,text="Phone:",font=("Arial",18,"bold"))
    phone.pack()
    lang=Label(frame1,text="Language:",font=("Arial",18,"bold"))
    lang.pack()
    frame1.pack(padx=10,pady=15)
    


    show.mainloop()
def update_data():
    pass




def main():
    setup()
    root = Tk()
    root.title("Main Page ")
    root.geometry("400x300")
    root.resizable(0,0)

    b1 = Button(root,text="Add Data",font=("Arial",20,"bold"),command = add_data)
    b1.place(x=30,y=100)

    b2 = Button(root,text="Show Data",font=("Arial",20,"bold"),command = show_data)
    b2.place(x=220,y=100)

    b3 = Button(root,text="Update Data",font=("Arial",20,"bold"),command = update_data)
    b3.place(x = 120,y = 200)
    root.mainloop()

main()

