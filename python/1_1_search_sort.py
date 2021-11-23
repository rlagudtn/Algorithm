import sys
input=sys.stdin.readline

n=input()
a=list(map(int,input().split()))
m=input()
nums=list(map(int,input().split()))

def binarySearch(v):
    start=0
    end=len(a)-1
    while(start<=end):
        mid=(start+end)//2
        if(a[mid]<v):
            start=mid+1

        elif(a[mid]>v):
            end=mid-1
        else:
            return 1
    return 0
a.sort()
for value in nums:
    print(binarySearch(value))

