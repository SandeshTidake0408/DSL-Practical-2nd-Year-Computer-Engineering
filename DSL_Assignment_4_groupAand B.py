
def enter_array():
    listt = []
    n = int(input("Enter the total no. of student : "))
    for i in range(n):
        x = int(input("Enter the roll no of student  in sorted Order: "))
        listt.append(x)
    print("Info Accepted")
    return listt


lisst = enter_array()


def check_attendace():  # linear search
    temp = lisst
    roll_no = int(input("Enter roll no. do you want to check : "))
    for i in range(len(temp)):
        if temp[i] == roll_no:
            print("The Roll No", roll_no, "Found at position ", i)
            break


def check():  # sentinel search
    temp = lisst
    l = len(temp)
    key = int(input("Enter Roll No. which do you want to check : "))
    last_element = temp[l - 1]
    temp[l - 1] = key
    i = 0
    while key != temp[i]:
        i += 1
    temp[l - 1] = last_element
    if i < l-1 or key == temp[l-1]:
        print("The Roll No ", temp[i], "found at position ", i)
    else:
        print("Match Not Found !")


def binary_search(arry, first, last, key):  # binary search
    # if first <= last:
    while (first <= last):
        mid = (first + last) // 2
        if key==arry[mid]:
            return mid
        elif key>arry[mid]:
            first = mid+1
        else:
            last =mid -1




        # if key == arry[mid]:
        #     print("The Element", arry[mid], "is found at Index ", mid)
        # elif key < arry[mid]:
        #     last = mid - 1
        #     return binary_search(arry, first, last)
        # elif key > arry[mid]:
        #     first = mid + 1
        #     return binary_search(arry, first, last)
        # else:
        #     return print("Match Not Found !!!")




def fibonaccisearch(A,X,n):
	f1=0
	f2=1
	f3=f1+f2
	offset=-1
	while(f3<n):
		f1=f2
		f2=f3
		f3=f1+f2
	while(f3>1):
		i = min(offset+f1,n-1)
		if (A[i] == X):
			return i
		else :
			if (X<A[i]):
				f3=f1
				f2=f2-f1
				f1=f3-f2
			else :
				f3=f2
				f2=f1
				f1=f3-f2
				offset=i
	if (f2 == 1 and (offset+1) < n and A[offset + 1] == X):

		return offset+1
	return -1

