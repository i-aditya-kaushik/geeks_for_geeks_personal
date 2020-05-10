def func(arr,n):
    if(1 in arr):
        return([1]*n)
    return(arr)

t= int(input())
for x in range(t):
    rc = list(map(int,input().split()))
    for x in range(rc[0]):
        arr = list(map(int,input().split()))
        c= (func(arr,rc[1]))
        for x in c:
            print(x,end=" ")
        print()
