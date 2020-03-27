import random as rd

a=[1232,14234,23,234,565,67,8867,8,5]
for _ in range(5):
    #random choising elements
    #whithout replacement
    ele=rd.choices(a)[0]
    a.remove(ele)  #thats use for no repitition
    print(ele)

a=[4,54,6,7,8,9,10]
rd.shuffle(a)
print(a)
a=[4,54,6,7,8,9,10,-234,7,1245]
print(sorted(a))

#using random function
print(rd.random())  #range from 0 to 1(floating)











