'''Write a Python program to compute following operations on String:'''
# a)To display word with the longest length.
# b)To determines the frequency of occurrence of particular character in the string.
# c)To check whether given string is palindrome or not .
# d)To display index of first appearance of the substring.
# e)To count the occurrences of each word in a given string.


global string
# string = str(input("Enter the string : "))
string = "This is the class class of data structure and algo"
n = len(string)


#use to split word of string into string you can also do it by using inbuild fuction string_name.split().
def splitt(name):
    strr =""
    arr=[]
    j=0 
    for i in range(j,n):
        if name[i]==" ":
            j=i+1 #for string next iteration from space+1 index
            arr.append(strr)
            strr="" #it will clear the string for next iteration
        strr=strr+name[i]
    arr.append(strr) #after the last word if there is no space since it can't append so it we can append it manually.  
    return arr
            
#1)
def long_word():

    temp = splitt(string)
    count = 0
    index = 0
    for i in range(len(temp)):
        temp_count = len(temp[i])
        if temp_count > count:
            count = temp_count
            index = i
    return temp[index]

# print(long_word())

#2)
def occurrence(ch):
    freq = 0
    for i in string:
        if i == ch:
            freq += 1
    return freq

#3)
def pallindrome():
    reverse = ""
    for i in string:
        reverse = i + reverse
    if string == reverse:
        return True
    else:
        return False

#4)
def sub_string(sub):
    sub_len = len(sub)
    for i in range((n-sub_len)+1):
        flag = 1
        for j in range(sub_len):
            if string[i+j] != sub[j]:
                flag = 0
                break
        if flag == 1:
            return flag
    

# sub="class of data"
# print(sub_string(sub))

#5)
def word_count():
    temp_list = splitt(string)
    new_list = []
    count = []
    for i in temp_list:
        if i not in new_list:
            new_list.append(i)
    for i in new_list:
        temp_count = 0
        for j in temp_list:
            if i == j:
                temp_count += 1
        count.append(temp_count)
    return new_list, count

# a,b=word_count()
# print(a,b)