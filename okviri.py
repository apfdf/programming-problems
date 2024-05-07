
from math import *

word = input()

rows = [['.' for _ in range(4 * len(word) + 1)] for _ in range(5)]

for i in range(len(word)):
    
    x = 4 * i + 2
    y = 2
    
    rows[y][x] = word[i]
    
    rows[y][x-2], rows[y][x+2] = '#', '#'
    rows[y-2][x], rows[y+2][x] = '#', '#'
    rows[y-1][x-1], rows[y-1][x+1], rows[y+1][x-1], rows[y+1][x+1] = '#', '#', '#', '#'

for i in range(len(word)):
    if ((i+1) % 3 == 0):
        x = 4 * i + 2
        y = 2
        
        rows[y][x-2], rows[y][x+2] = '*', '*'
        rows[y-2][x], rows[y+2][x] = '*', '*'
        rows[y-1][x-1], rows[y-1][x+1], rows[y+1][x-1], rows[y+1][x+1] = '*', '*', '*', '*'

for row in rows:
    print("".join(row))
