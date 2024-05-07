
def dp(mem, n):
    if n in mem:
        return mem[n]
    if n == 1:
        return 1
    if n == 2:
        return 2
    return dp(mem, n-1) + dp(mem, n-2) + 1

N = int(input())

print(dp({}, N))
