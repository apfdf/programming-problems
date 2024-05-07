
n = int(input())
while n != 0:
    
    rows = [input() for _ in range(n)]
    
    height = n
    width = max([len(row) for row in rows])
    grid = [[' ' for j in range(width)] for i in range(height)]
    
    for i in range(n):
        for j in range(len(rows[i])):
            if rows[i][j] == '-':
                grid[i][j] = '|'
            elif rows[i][j] == '|':
                grid[i][j] = '-'
            else:
                grid[i][j] = rows[i][j]
    
    rot_grid = [[grid[height-1-i][j] for i in range(height)] for j in range(width)]
    rot_height = width
    rot_width = height
    
    s = ""
    for i in range(rot_height):
        last_white = rot_width
        while last_white > 0:
            if rot_grid[i][last_white-1] != ' ':
                break
            last_white -= 1
        print("".join(rot_grid[i][0 : last_white]))        
    print("")

    n = int(input())
