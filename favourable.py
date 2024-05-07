
mem = {}
def paths(current_node, connections):

    global mem

    if current_node in mem:
        return mem[current_node]

    if current_node == 1:
        mem[current_node] = 1
        return 1
    s = 0
    for connection in connections:
        if current_node in connection[1 : 4]:
            s += paths(connection[0], connections)
    
    mem[current_node] = s
    return s

T = int(input())

for _ in range(T):

    connections = []
    favourables = []

    S = int(input())
    for i in range(S):
        
        inp = input().split()
        if inp[1] == "favourably":
            favourables.append(int(inp[0]))
            continue
        elif inp[1] == "catastrophically":
            continue

        connections.append(list(map(int, inp)))
    
    print(*favourables)

    total_paths = 0
    for favourable in favourables:
        total_paths += paths(favourable, connections)
    
    print(total_paths)
