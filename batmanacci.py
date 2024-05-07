
import sys

sys.setrecursionlimit(10**5)

N, K = map(int, input().split())

fibs = [1, 1]

for i in range(2, N):
    fib = fibs[i-1]+fibs[i-2]
    fibs.append(fibs[i-1]+fibs[i-2])

def get_letter(i, k, fibs):

    if i == 0:
        return 'N'
    elif i == 1:
        return 'A'
    if k < fibs[i-2]:
        return get_letter(i-2, k, fibs)
    else:
        return get_letter(i-1, k-fibs[i-2], fibs)
    
print(get_letter(N-1, K-1, fibs))
