
N, M = map(int, input().split())
rights = [0 for _ in range(N)]

for i in range(N):
    
    sequence = input().split()
    
    for k in range(1, M+1):
        
        right = ""
        if k % 3 == 0:
            right += "fizz"
        if k % 5 == 0:
            right += "buzz"
        
        if right == "":
            right += str(k)
        
        if right == sequence[k-1]:
            rights[i] += 1

print(rights.index(max(rights)) + 1)
