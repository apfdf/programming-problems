gcd = lambda a,b: gcd(b, a - (a//b)*b) if b != 0 else a
print(gcd(18, 8))