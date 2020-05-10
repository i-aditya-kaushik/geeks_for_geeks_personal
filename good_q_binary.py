def func(n):
    b = ((bin(n)))
    if(len(b) %2 ==0):
        d = (len(b)-2)//2
        n = n ^ (1 << (d))
        n = n ^ (1 << (d-1))
    else:
        d = (len(b)-2)//2
        n = n ^ (1 << (d))
    print(n)
    
t= int(input())
for x in range(t):
    n = int(input())
    func(n)