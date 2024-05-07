
def get_origin_paths(n, i, j):
    if abs(i) > n or abs(j) > n:
        return 0
    if n == 0:
        return 1 if i == 0 and j == 0 else 0
    coords = [(i, j+1), (i, j-1), (i+1, j), (i+1, j-1), (i-1, j), (i-1, j+1)]
    return sum([get_origin_paths(n-1, coord[0], coord[1]) for coord in coords])

cases_amount = int(input())

for _ in range(cases_amount):
    steps = int(input())
    coords = (0, 0)
    print(get_origin_paths(steps, 0, 0))
