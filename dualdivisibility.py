
a, b = map(int, input().split())

divisors = 0
b_multiple = b
while b_multiple <= a:
    if a % b_multiple == 0:
        divisors += 1
    b_multiple += b

print(divisors)
