i=lambda:input()
for j in range(int(i())):
 i()
 R=range(int(i()))
 P=sorted(int(i().split()[1])for _ in R)
 print(sum(abs(k+1-P[k])for k in R))