
N = int(input())
matches = [list(map(int, input().split())) for _ in range(N)]

diffs = list(map(lambda p: p[0] - p[1], matches))
diffs.sort(key=abs)

unique_diffs = []
for diff in diffs:
    if abs(diff) not in unique_diffs:
        unique_diffs.append(abs(diff))

unique_diffs.sort()

F_wins = sum([1 if d > 0 else 0 for d in diffs])
S_wins = sum([1 if d < 0 else 0 for d in diffs])

match_dif = F_wins - S_wins

best_match_dif = F_wins - S_wins
best_bound = 0

piv = 0

for unique_diff in unique_diffs:
    
    # går att förbättra så att man bara går igenom diffs en gång istället för len(unique_diffs) gånger (max N gånger)

    for i in range(piv, N):
        piv = i
        if abs(diffs[i]) != unique_diff:
            break
        if diffs[piv] > 0:
            match_dif -= 1
        elif diffs[piv] < 0:
            match_dif += 1

    if match_dif > best_match_dif:
        best_match_dif = match_dif
        best_bound = unique_diff

print(best_bound)

