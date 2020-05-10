def fun(arr,n):
    sum1=1
    for x in range(n):
        if(arr[x]!=sum1):
            print(arr[x],sum1)
        sum1+=1

t = int(input())
for x in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    fun(arr,n)