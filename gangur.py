
sections = list(input())

total_passings = 0

opposites = sum([1 if section == '<' else 0 for section in sections])

for i in range(len(sections)):
    if sections[i] == '>':
        total_passings += opposites
    elif sections[i] == '<':
        opposites -= 1
    if opposites == 0:
        break

print(total_passings)
