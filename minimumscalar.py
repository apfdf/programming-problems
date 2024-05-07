
cases = int(input())

for i in range(cases):
    
    d = int(input())
    
    v1 = list(map(int, input().split()))
    v2 = list(map(int, input().split()))
    
    v1.sort()
    v2.sort(reverse=True)
    
    prod = sum([v1[i]*v2[i] for i in range(d)])
    
    print("Case #" + str(i+1) + ": " + str(prod))
