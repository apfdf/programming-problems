
fellas = int(input())
queue = list(map(int, input().split()))

queue.remove(0)
queue.insert(0, 0)

total_happiness = sum([queue[i] * (i+1) for i in range(len(queue))])

largest_happiness = total_happiness

for i in range(1, len(queue)):
    total_happiness -= queue[i]
    if total_happiness > largest_happiness:
        largest_happiness = total_happiness

print(largest_happiness)



'''
def get_happiness(queue):
    return sum([queue[i] * (i+1) for i in range(len(queue))])

queue.remove(0)
queue.insert(0, 0)

largest_happiness = get_happiness(queue)

for i in range(1, len(queue)):

    queue[i-1] = queue[i]
    queue[i] = 0

    total_happiness = get_happiness(queue)

    if total_happiness > largest_happiness:
        largest_happiness = total_happiness
    
print(largest_happiness)
'''
