
letter = input()
print("Kannski" if letter.lower()  not in "abcdefghijklmnopqrstuvwxyz" else ("Jebb" if letter.lower() in "aeiou" else "Neibb"))
