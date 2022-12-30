def enter_array():
    listt = []
    n = int(input("Enter the total no. of student : "))
    for i in range(n):
        x = float(input("Enter the percentage Of student : "))
        listt.append(x)
    print("Info Accepted")
    return listt


'''Bubble Sort'''
def bubble_sort(arry):
    for j in range (0,len(arry)-1):
        for i in range (0,len(arry)-1):
            if arry[i]>arry[i+1]:
                temp=arry[i]
                arry[i]=arry[i+1]
                arry[i+1]=temp
    print("This is required Sorted aray : ",arry)


    
bubble_sort(enter_array())


'''Quick Sort'''
def partition(arr,lb,ub):
    pivot=arr[lb]
    start =lb
    end= ub
    while(start<end):
        while(arr[start]<=pivot and start<ub):
            start+=1
        while(arr[end]>pivot and end>lb):
            end-=1
        if start<end:
            temp = arr[start]
            arr[start]=arr[end]
            arr[end]=temp
    temp = arr[lb]
    arr[lb]=arr[end]
    arr[end]=temp
    return end
def quick_sort(array,lb,ub):
    if(lb<ub):
        loc=partition(array,lb,ub)
        quick_sort(array,lb,loc-1)
        quick_sort(array,loc+1,ub)

a=[5,45,10,21,2,96,19,74,12]
print("Unsorted Array : ",a)
quick_sort(a,0,len(a)-1)
print("After Sorting : ",a)



'''Selection Sort'''

def selection_sort(arr):
    for i in range(len(arr)-1):
        min = i
        for j in range(i+1,len(arr)):
            if arr[j]<arr[min]:
                min=j
        temp=arr[min]
        arr[min]=arr[i]
        arr[i]=temp
    
selection_sort(a)
print(a)

'''Insertion Sort'''

def insertion_sort(arr):
    for i in range(1,len(arr)):
        temp = arr[i]
        j=i-1
        while(j>=0 and arr[j]> temp ):
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=temp

insertion_sort(a)
print(a)


'''Bucket Sort'''

def bucketSort(arr, noOfBuckets):
    max_ele = max(arr)
    min_ele = min(arr)
    rnge = (max_ele - min_ele) / noOfBuckets
    temp = []
  
    for i in range(noOfBuckets):
        temp.append([])
  
    for i in range(len(arr)):
        diff = (arr[i] - min_ele) / rnge - int((arr[i] - min_ele) / rnge)

        if(diff == 0 and arr[i] != min_ele):
            temp[int((arr[i] - min_ele) / rnge) - 1].append(arr[i])
  
        else:
            temp[int((arr[i] - min_ele) / rnge)].append(arr[i])
  
    for i in range(len(temp)):
        if len(temp[i]) != 0:
            temp[i].sort()
    k = 0
    for lst in temp:
        if lst:
            for i in lst:
                arr[k] = i
                k = k+1

print(a)
noOfBuckets = 5
bucketSort(a, noOfBuckets)
print("Sorted array: ", a)



