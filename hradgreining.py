
DNA = input()

has_virus = False
for i in range(len(DNA)-2):
    if DNA[i] == 'C' and DNA[i+1] == 'O' and DNA[i+2] == 'V':
        has_virus = True
        break

if has_virus:
    print("Veikur!")
else:
    print("Ekki veikur!")
    