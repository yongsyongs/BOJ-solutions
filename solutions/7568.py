N = int(input())
tuples = tuple(
    (tuple([int(x) for x in input().split(" ")]) for _ in range(N))
)
ranks = [None] * N
for i in range(N):
    k = 0
    for j in range(N):
        if i == j: continue
        if tuples[i][0] < tuples[j][0] and tuples[i][1] < tuples[j][1]:
            k += 1
    ranks[i] = k + 1

print(*ranks)