
p=lambda x:input()



T = int(input())
input()

for i in range(T):
    N = int(input())
    preferred = [int(input().split()[1]) for j in range(N)]
    preferred.sort()
    badness = 0
    for j in range(N):
        badness += abs(j+1 - preferred[j])
    print(badness)
    if (i < T-1):
        input()
