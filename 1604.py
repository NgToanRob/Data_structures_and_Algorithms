k = int(input())
freq = list(map(int, input().split()))

signs = []
for i in range(k):
    signs.append((i+1, freq[i]))

signs.sort(key=lambda x: x[1], reverse=True)

order = []
for sign in signs:
    order += [sign[0]] * sign[1]

print(*order)