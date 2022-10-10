N = int(input())
words = [input() for _ in range(N)]

cnt = 0
for word in words:
    if len(word) < 3:
        cnt += 1
        continue

    occurred_char = []
    is_group_word = True
    for c in word:
        if c not in occurred_char:
            occurred_char.append(c)
        else:
            if occurred_char[-1] != c:
                is_group_word = False
                break
    if is_group_word:
        cnt += 1
    
print(cnt)