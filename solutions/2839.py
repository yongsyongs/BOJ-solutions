N = int(input())

def solution(N):
    is_diviable = False
    for i in range(N // 5, -1, -1):
        x = N - 5 * i
        if x % 3 == 0:
            is_diviable = True
            break

    if is_diviable:
        return x // 3 + i
    else:
        return -1

print(solution(N))