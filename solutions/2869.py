from math import floor, ceil

inputs = input().split(" ")
A, B, V = [int(n) for n in inputs]


def solution(A, B, V):
    x = (V - B) / (A - B)
    if x > floor(x):
        x = ceil(x)

    return int(x)


print(solution(A, B, V))
