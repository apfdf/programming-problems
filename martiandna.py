
N, K, R = map(int, input().split())
DNA = list(map(int, input().split()))

base_requirements = {}
bases = []

for _ in range(R):
    base, amount = map(int, input().split())
    if base not in bases:
        bases.append(base)
        base_requirements[base] = amount

for base in bases:
    if DNA.count(base) < base_requirements[base]:
        print("impossible")
        quit()

lo = 0
hi = len(DNA) - 1

base_amounts = {}
for base in bases:
    base_amounts[base] = DNA.count(base)

for i in range(len(DNA)):
    # minska hi så mycket som möjligt
    if DNA[hi] in bases:
        val = DNA[hi]
        if base_amounts[val] > base_requirements[val]:
            base_amounts[val] = base_amounts[val] - 1
        else:
            break
    hi -= 1
    
shortest_subset = hi - lo + 1
for i in range(1, len(DNA)):
    
    lo = i
    base = DNA[i-1]
    if base not in bases:
        continue
    base_amounts[base] -= 1


    if base_amounts[base] < base_requirements[base]:
        is_last = True
        for j in range(hi+1, len(DNA)):
            if DNA[j] == base:
                is_last = False
                hi = j
                break
        if is_last:
            break

    length = hi - lo + 1
    if length < shortest_subset:
        shortest_subset = length
        
print(shortest_subset)

