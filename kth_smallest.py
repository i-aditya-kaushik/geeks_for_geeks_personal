
def func(nums, k):
    def check(guess):
        ret = ll = 0
        for rr, x in enumerate(nums):
            while x - nums[ll] > guess:
                ll += 1
            ret += rr - ll
        return ret >= k
    nums.sort()
    res = 0
    max1 = nums[-1] - nums[0]
    while res < max1:
        mi = (res + max1) / 2
        if check(mi):
            max1 = mi
        else:
            res = mi + 1
    print(res)
    
for x in range(int(input())):
    nk = list(map(int,input().split()))
    l = list(map(int,input().split()))
    func(l,nk[1])