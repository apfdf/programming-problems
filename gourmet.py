
from math import *

M = int(input())
N = int(input())

l = [int(input()) for _ in range(N)]

def dp(l, m, n, p, s):
    
    if s == m:
        return factorial(p)
    if s > m:
        return 0
    if n == len(l):
        return 0
    
    val = l[n]
    return dp(l, m, n, p+1, s+val) + dp(l, m, n+1, p, s)

print(dp(l, M, 0, 0, 0))
