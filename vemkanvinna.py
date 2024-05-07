
grid = [input().split() for _ in range(3)]

# kolla igenom alla rader av tre, om någon är möjlig för de två personerna

rows = []
for i in range(3):
    rows.append([grid[i][j] for j in range(3)])
for j in range(3):
    rows.append([grid[i][j] for i in range(3)])
rows.append([grid[0][0], grid[1][1], grid[2][2]])
rows.append([grid[2][0], grid[1][1], grid[0][2]])

A = False
J = False

total_x_amount = grid[0].count('X') + grid[1].count('X') + grid[2].count('X')
total_o_amount = grid[0].count('O') + grid[1].count('O') + grid[2].count('O')
total_empty_amount = 9 - total_x_amount - total_o_amount

for row in rows:
    
    row_empty_amount = row.count('_')
    row_x_amount = row.count('X')
    row_o_amount = row.count('O')

    if row_x_amount == 0 or row_o_amount == 0:
        
        if row_o_amount == 0:
            if 5 - total_x_amount >= 3 - row_x_amount:
                J = True
        
        if row_x_amount == 0:
            if 4 - total_o_amount >= 3 - row_o_amount:
                A = True

if A == True:
    if J == True:
        print("Abdullah och Johan kan vinna")
    else:
        print("Abdullah kan vinna")
elif J == True:
    print("Johan kan vinna")
else:
    print("ingen kan vinna")
