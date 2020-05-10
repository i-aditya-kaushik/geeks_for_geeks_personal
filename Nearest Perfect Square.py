#code
import math
def func(a):
    c = int(math.sqrt(a))
    if(int(math.sqrt(a)) == math.sqrt(a)):
        c-=1
    d= int(math.sqrt(a)) + 1
    if(min(pow(d,2)-a , a- pow(c,2)) == pow(d,2)-a):
        return(pow(d,2))
    return(pow(c,2))
    


t = int(input())
for x in range(t):
    print(func(int(input())))