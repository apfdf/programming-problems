
r, c = map(int, input().split())
grid = [list(map(int, list(input()))) for _ in range(r)]
mesh_grid = [[-1 for j in range(c)] for i in range(r)]

mesh_index = 0
for i in range(r):
    for j in range(c):
        
        if mesh_grid[i][j] != -1:
            continue
        
        num = grid[i][j]
        to_check = [(i, j)]

        check_index = 0
        while check_index < len(to_check):
            
            check_i = to_check[check_index][0]
            check_j = to_check[check_index][1]
            
            mesh_grid[check_i][check_j] = mesh_index
            
            if check_i > 0:
                if grid[check_i-1][check_j] == num and mesh_grid[check_i-1][check_j] == -1:
                    to_check.append((check_i-1, check_j))
            if check_i < r-1:
                if grid[check_i+1][check_j] == num and mesh_grid[check_i+1][check_j] == -1:
                    to_check.append((check_i+1, check_j))
            if check_j > 0:
                if grid[check_i][check_j-1] == num and mesh_grid[check_i][check_j-1] == -1:
                    to_check.append((check_i, check_j-1))
            if check_j < c-1:
                if grid[check_i][check_j+1] == num and mesh_grid[check_i][check_j+1] == -1:
                    to_check.append((check_i, check_j+1))
            
            check_index += 1
        
        mesh_index += 1

n = int(input())
for _ in range(n):
    
    r1, c1, r2, c2 = map(int, input().split())
    condition = "neither"
    if mesh_grid[r1-1][c1-1] == mesh_grid[r2-1][c2-1]:
        condition = "binary" if grid[r1-1][c1-1] == 0 else "decimal"
    print(condition)
