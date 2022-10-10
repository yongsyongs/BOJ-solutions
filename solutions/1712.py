from math import floor, ceil
inputs = input().split(' ')
A, B, C = [int(n) for n in inputs]

def solution(A, B, C):
    if C <= B:
        return -1
    else:
        x = A / (C - B)
        if x > floor(x):
            x = ceil(x)
        else:
            x += 1
        return int(x)

print(solution(A, B, C))