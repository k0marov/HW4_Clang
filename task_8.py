n = int(input()) 
a = list(map(int, input().split())) 
a.sort() 

cache = {} 

def find_sum(i, j): 
    if (i, j) in cache: 
        return cache[(i, j)] 
    n = j-i
    if n <= 0: 
        return 0
    if n == 1: 
        return float('inf')
    if n <= 3: 
        return a[j-1] - a[i+0] 
    first = a[i+1] - a[i+0] 
    last = a[j-1] - a[j-2] 
    best = float('inf')
    # connect with both ends 
    best = min(best, a[i+2]-a[i+1] + a[j-2]-a[j-3] + find_sum(i+3, j-3))
    # connect with first end but not last end 
    best = min(best, a[i+2]-a[i+1] + find_sum(i+3, j-2)) 
    # connect with last end but not first end 
    best = min(best, a[j-2]-a[j-3] +find_sum(i+2, j-3))
    # don't connect
    best = min(best, find_sum(i+2, j-2))
    res = best+first+last 
    cache[(i, j)] = res 
    return res 

print(find_sum(0, n))
