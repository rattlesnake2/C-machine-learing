#this function finds whether num is present in list:arr
def findNumberInList(arr,num):
    #traverse the arr
    for i in arr:
        #match found
        if i==num:
            return True
    #match not found
    return False;
#this functionfinds if any common element in x,y
def intersect(x,y):
    #for every element in x, search if that element exist in y
    for i in x:
        #if found, return true
        if findNumberInList(y,i)==True:
            return True
    #none of element in x found in y
    return False
#take average of whole list except min and max
def centeredAverage(arr):
    sum=0
    minNum=1000000
    maxNum=-1000000
    #traverse list and take sum of all numbers, find minimum and maximum
    for i in arr:
        sum=sum+i
        if i<minNum:
            minNum=i
        if i>maxNum:
            maxNum=i
    #remove minimum and maximum from sum
    sum=sum-minNum-maxNum
    #return the average of n-2 elements
    return sum/(len(arr)-2)

#this function remove element from arr at index n
def removen(arr,n):
    #this function is the simplest iplementation of removing element
    arr.pop(n)
    #return the arr after removing
    return arr
#this function find any duplicates in list:arr
def duplicate(arr):
    i=0
    #traverse the list and find if similar element exist in list
    while i<len(arr):
        num=arr[i]
        arr[i]=-101010
        #first we modify number so that same number is not detected
        found=findNumberInList(arr,num)
        #again restore the original number
        arr[i]=num
        # if match found
        if found==True:
            return True
        i=i+1
    #match not found
    return False

#testing all functions one by one
    
print('Checking intersect function....intersect([2, 4, 1, 8], [3, 1, 5, 9])')
intersect([2, 4, 1, 8], [3, 1, 5, 9])
print('Checking intersect function....intersect([2, 4, 8], [3, 5, 9])')
intersect([2, 4, 8], [3, 5, 9])

print('Checking centeredAverage function....centeredAverage([2, 10, 3, 5])')
centeredAverage([2, 10, 3, 5])

print('Checking removen function....removen([3, 1, 5, 9], 2)')
removen([3, 1, 5, 9], 2)

print('Checking duplicate function....duplicate([70, 90, 70, 95, 90])')
duplicate([70, 90, 70, 95, 90])
print('Checking duplicate function....duplicate([70, 90, 80, 95])')
duplicate([70, 90, 80, 95])

