#defining function with parameters array, value to search
def binarySearch(arr,x):
    #low,high indices of array
    low=0
    high=9999
    #count steps, assuming if we find 9467 at first attempt, we return 1 step
    count=1
    while low<=high:
        #mid index
        mid=int((low+high)/2)
        #element found
        if arr[mid]==x:
            print("Element found!!")
            return count
        #element not found, count increased by 1
        count=count+1
        #searching in right half
        if arr[mid]<x:
            low=mid+1
        #searching in left half
        else:
            high=mid-1
    print("Element Not found!!")
    return count
        

#generating uniqie random list
import random
numberslist=[]
number=0
while number<10000:
    value=random.randint(1,20000)
    if not(value in numberslist):
        numberslist.append(value)
        number=number+1
#sorting list so we can apply binary search
numberslist.sort()
#getting steps and printing
steps=binarySearch(numberslist,9467)
print("Steps required: ",steps)