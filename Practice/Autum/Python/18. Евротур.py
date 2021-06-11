chars = [0] * 26
print("Стоп слово")
s = str(input())
words = ("hallo", "klempner", "das", "ist", "fantastisch", "fluggegecheimen")
a = ord('a')
for i in words:
    for c in i:
        chars[ord(c) - a] += 1
chance = 1
result = sum(chars)
for c in s:
    chance *= chars[ord(c) - a] / result
    if (chance == 0):
        break
print(chance)
