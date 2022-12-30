# Group A - Assignment 1

# In second year computer engineering class, group A students play cricket,
# group B students play badminton and group C students play football. 
# Write a python program using functions to compute following: - 
# a)List of students who play both cricket and badminton 
# b)List of students who play either cricket or badminton but not both 
# c)Number of students who play neither cricket nor badminton
# d)Number of students who play cricket and football but not badminton.
# (Note- While realizing the group, duplicate entries should be avoided, Do not use SET built-in functions)
a = []
b = []
c = []
ccric = int(input("Enter the number of student who plays criket : "))
for i in range(ccric):
    a.append(input("Enter the name of student :"))
print("You Enter following names : ", a)

cbad = int(input("Enter the number of student who plays badminton : "))
for i in range(cbad):
    b.append(input("Enter the name of student :"))
print("You Enter following names : ", b)

cfoot = int(input("Enter the number of student who plays football : "))
for i in range(cfoot):
    c.append(input("Enter the name of student :"))
print("You Enter following names : ", c)


def a_union_b():
    listt = []
    listt = a
    for i in b:
        if i in a:
            pass
        else:
            listt.append(i)
    return listt


def a_union_c():
    list_0 = []
    list_0 = a
    for i in c:
        if i in a:
            pass
        else:
            list_0.append(i)
    return list_0

#1)
list_1 = []
def cric__bad():
    for i in a:
        if i in b:
            list_1.append(i)
    print("List of Student who play both Cricket and Badminton :", list_1)

cric__bad()

#2)
def cric_and_bad():
    temp = a_union_b()
    list_2 = []
    for i in temp:
        if i in list_1:
            pass
        else:
            list_2.append(i)
    print("List of Student who play either cricket or badminton not both :", list_2)


cric_and_bad()

#3)
def pure_football():
    temp = []
    for i in c:
        if i in a:
            pass
        else:
            temp.append(i)
    list_3 = []
    for i in temp:
        if i in b:
            pass
        else:
            list_3.append(i)
    print("Number of student who play neither cricket nor badminton : ", len(list_3))
    print("List of student who play neither cricket nor badminton : ", list_3)


pure_football()

#4)
def cric_foot():
    list_4 = []
    for i in a_union_c():
        if i in b:
            pass
        else:
            list_4.append(i)
    print("Number of Student who play cricket and football not badminton : ", len(list_4))
    print("List of Student who play cricket and football not badminton :", list_4)


cric_foot()
