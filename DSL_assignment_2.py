N = int(input("Enter the no. of student : "))
print("If any student was not appeared for exam then enter 'ab'")
print("Please do not enter marks below 0 and greater than 30")
array = []


def get_data():
    for i in range(N):
        n = input("Enter the mark of student one by one : ")
        array.append(n)


get_data()


def absent_count():
    count = 0
    for i in array:
        if i == "ab":
            count += 1
    return count


def avarage():
    sum = 0
    for i in array:
        if i != 'ab':
            sum = sum + int(i)
    average = sum / (N-absent_count())
    return average


def high_low():
    high, low = 0, int(array[0])
    for i in array:
        if i != 'ab':
            i = int(i)
            if i > high:
                high = i
            if i < low:
                low = i
    return low, high


def frequency():
    frequency_count = 1
    mark = 0
    for i in array:
        temp = 0
        element = 0
        if i != 'ab':
            for j in array:
                if i == j:
                    temp += 1
                    element = i

        if temp > frequency_count:
            frequency_count = temp
            mark = element
        else:
            temp = 0
    return mark, frequency_count

def menu():
    while True:
        print("Which Operation do you want : \n1)The average Score of the class.\n2)Highest score and lowest score of class.\n3)Count of student who were absent for the test.\n4)Display mark with highest frequency.")
        ch = int(input("Enter Your Choice :"))
        match ch:
            case 1:
                hold=avarage()
                print("Average of Class is ",hold)
            case 2:
                low, high =high_low()
                print("The Low And High mark of class are ",low, high)
            case 3:
                hold=absent_count()
                print("No. of absent student are ",hold)
            case 4:
                mark,freq=frequency()
                if freq==1:
                    print("All Student have different marks")
                else:
                    print("Mark ",mark,"have highest frequency of ",freq)
        print("Do You want to Continue [y/n] ")
        temp= input()
        if temp=='y':
            continue
        else:
            break

menu()



