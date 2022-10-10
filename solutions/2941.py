CAS = ("c=", "c-", "d-", "lj", "nj", "s=", "z=")
inputs = input()

def count(inputs):
    if len(inputs) == 2:
        if inputs in CAS: return 1
        else: return 2
    

    cnt = 0
    i = 0
    while i < len(inputs) - 2:
        two_len_char = inputs[i : i + 2]
        three_len_char = inputs[i : i + 3]
        if three_len_char == 'dz=':
            cnt += 1
            i += 3
        elif two_len_char[-1] in ('=', '-', 'j') and two_len_char in CAS:
            cnt += 1
            i += 2
        else:
            cnt += 1
            i += 1

    if i == len(inputs) - 1:
        cnt += 1
    elif i == len(inputs) - 2:
        if inputs[-2:] in CAS:
            cnt += 1
        else:
            cnt += 2
    return cnt

print(count(inputs))