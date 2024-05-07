
word = input()

alphabet = "abcdefghijklmnopqrstuvwxyz"

def get_pivot(s: str) -> int:
    
    lowest = min(s)


    if s.count(lowest) > 1:

        indexes = []
        for i in range(len(s)):
            if s[i] == lowest:
                indexes.append(i)

        for i in range(s.count(lowest)):
            
            letters = [s[index-i] for index in indexes]
            lo = min(letters)

            for index in indexes:
                if s[index] > lo:
                    indexes.remove(index)
            
            if len(indexes) == 1:
                break

        return indexes[0]
    else:
        return s.index(lowest)

pivot_1 = get_pivot(word)
pivot_2 = pivot_1 + 1 + get_pivot(word[pivot_1+1: len(word)-1])

sequence_1 = list(reversed(word[0: pivot_1+1]))
sequence_2 = list(reversed(word[pivot_1+1: pivot_2+1]))
sequence_3 = list(reversed(word[pivot_2+1: len(word)]))

s = ""
for char in sequence_1:
    s += char
for char in sequence_2:
    s += char
for char in sequence_3:
    s += char

print(s)

# find the earliest letter in the word, that will be where the first split is
# then do the exact same fore the rest of the word

# or just try all the possible ones

# just get the earliest three as left as possible
