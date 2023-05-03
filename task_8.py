n = int(input())
a = list(map(int, input().split()))
a.sort()

cache = [None]*n


def find_sum(i):
    if cache[i] is not None:
        return cache[i]
    if n-i <= 0:
        return 0
    if n-i == 1:
        return float('inf')
    if n-i <= 3:
        return a[-1] - a[i]
    best = a[i+1]-a[i] + min(a[i+2]-a[i+1] + find_sum(i+3), find_sum(i+2))
    cache[i] = best
    return best


print(find_sum(0))
