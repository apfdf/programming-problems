
vowels = "aeiouy"

N = int(input())
words = input().split()

res_string = ""
for word in words:
    for i in range(len(word)):
        if i < len(word)-2:
            if word[i] in vowels and word[i+1] not in vowels and word[i+2] not in vowels:
                continue
        res_string += word[i]
    res_string += " "

res_string = res_string[::-1]

print(res_string.removeprefix(" "))
