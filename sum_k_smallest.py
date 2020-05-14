def func(l,k):
    l.sort()
    res=0
    for x in range(k):
        res+=l[x]
    print(res)

for x in range(int(input())):
    nk = list(map(int,input().split()))
    l = list(map(int,input().split()))
    func(l,nk[1])