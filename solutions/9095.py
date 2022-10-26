from math import factorial

def downstream(A):
    # 1 + 1 = 2
    # 1 + 2 = 3
    lower_cases = set()
    if A[0] >= 3:
        new_case = (A[0] - 3, A[1], A[2] + 1)
        lower_cases.add(new_case)
    if A[0] >= 2:
        new_case = (A[0] - 2, A[1] + 1, A[2])
        lower_cases.add(new_case)
    if A[0] >= 1 and A[1] >= 1:
        new_case = (A[0] - 1, A[1] - 1, A[2] + 1)
        lower_cases.add(new_case)
    return lower_cases

def get_count(A):
    assert isinstance(A, tuple)
    f = factorial(A[0] + A[1] + A[2])
    d = factorial(A[0]) *  factorial(A[1]) * factorial(A[2])
    return f // d


T = int(input())
for _ in range(T):
    n = int(input())
    M = n // 3 + 1
    upper_cases = {(n, 0, 0)}
    all_cases = {(n, 0, 0)}

    for i in range(M + 1):
        lower_cases = set()
        for case in upper_cases:
            lower_cases |= downstream(case)
        all_cases |= lower_cases
        upper_cases = lower_cases

    cnt = 0
    for case in all_cases:
        cnt += get_count(case)

    print(cnt)
            